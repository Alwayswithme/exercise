#!/bin/python3
#
# Author     :  Ye Jinchang
# Date       :  2015-05-15 12:13:38
# Title      :  sysinfo

import subprocess
import os
import sys
import string
import re

def check_permission():
    euid = os.geteuid()
    if euid != 0:
        print('Script not started as root. Running sudo..')
        args = ['sudo', sys.executable] + sys.argv + [os.environ]
        # the next line replaces the currently-running process with the sudo
        os.execlpe('sudo', *args)


class System_Info:

    @staticmethod
    def shell_output(cmd, in_shell=False):
        return str(subprocess.check_output(cmd, shell=in_shell), 'utf-8')

    def product(self):
        cmd = ['dmidecode', '-s', 'system-product-name']
        output = System_Info.shell_output(cmd)
        return output
    
    def distro(self):
        cmd = ['head', '-1', '/etc/issue']
        output = System_Info.shell_output(cmd)
        return output
    
    def kernel(self):
        cmd = ['uname', '-o', '-r']
        output = System_Info.shell_output(cmd)
        return output

    def processor(self):
        cmd = ['dmidecode', '-s', 'processor-version']
        output = System_Info.shell_output(cmd)
        return output

    def memory(self):
        cmd = ['dmidecode', '-t', 'memory']
        parsing = False
        splitter = ': '
        attrs = ['Size', 'Type', 'Speed', 'Manufacturer', 'Locator']
        mem_list = []
        with subprocess.Popen(cmd, stdout=subprocess.PIPE,
                              bufsize = 1, universal_newlines = True) as p:
            for i in p.stdout:
                line = i.strip()
                if not parsing and line == 'Memory Device':
                    parsing = True
                    mem = {}
                if parsing and splitter in line:
                    (key, value) = line.split(splitter, 1)
                    if key in attrs:
                        mem[key] = value

                # read a empty, end the parsing
                elif parsing and not line:
                    parsing = False
                    mem_list.append(mem)
        return mem_list
    
    def disk(self):
        # query how many disk
        sds = System_Info.shell_output('ls -1d /dev/sd[a-z]', in_shell=True)
        sd_list = [x for x in sds.split('\n') if x]
        cmd = ['smartctl', '-i']
        parsing = False
        splitter = ':'
        disk_list = []
        attrs = ['Model Family', 'Device Model', 'User Capacity']
        for i in sd_list:
            new_cmd = cmd[:]
            new_cmd.append(i)
            with subprocess.Popen(new_cmd, stdout=subprocess.PIPE,
                    bufsize = 1, universal_newlines=True) as p:
                for j in p.stdout:
                    line = j.strip()
                    if not parsing and 'START OF INFORMATION' in line:
                        parsing = True
                        device = {}
                    if parsing and splitter in line:
                        key, value = line.split(splitter, 1)
                        value = value.strip()
                        if key in 'Model Family':
                            device['model'] = value
                        elif key in 'Device Model':
                            device['device'] = value
                        elif key in 'User Capacity':
                            p = re.compile('\[.*\]')
                            m = p.search(value)
                            device['capacity'] = m.group()
                    elif parsing and not line:
                        parsing = False
                        disk_list.append(device)

        return disk_list
        
    def __init__(self):
        self.product_name = self.product()
        self.distibution = self.distro()
        self.kernel = self.kernel()
        self.processor = self.processor()
        self.memory = self.memory()
        self.disk = self.disk()
    
    def __str__(self):
        info = []
        info.append('Product   : {0}'.format(self.product_name))
        info.append('Distro    : {0}'.format(self.distibution))
        info.append('Kernel    : {0}'.format(self.kernel))
        info.append('Processor : {0}'.format(self.processor))
        mem_size = [ self.conv_memsize(i['Size']) for i in self.memory]
        total = sum(mem_size)
        mem_detail = [ self.extract_mem_detail(i) for i in self.memory]
        info.append('Memory    : {0} MiB Total\n'.format(total))
        for i in mem_detail:
            info.append('            {0}\n'.format(i))

        for i in self.disk:
            info.append('Disk      : {0} {1}\n'.format(i['device'], i['capacity']))
        return ''.join(info)

    def extract_mem_detail(self, mem):
        # maybe no memory in this slot
        if 'Unknown' in mem['Type'] and 'No Module Installed' in mem['Size']:
            return ''
        line = '{slot}: {manufa} {type} {speed} '.format(
                slot=mem['Locator'], manufa=mem['Manufacturer'],
                type=mem['Type'], speed=mem['Speed'])
        return line

    def conv_memsize(self, size_str):
        (size, unit) = size_str.split(' ', 1);
        try:
            return int(size)
        except ValueError:
            return 0


check_permission()
system_info = System_Info()
print(system_info)
