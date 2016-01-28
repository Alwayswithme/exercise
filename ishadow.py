#!/bin/python

import re
import json
import urllib.request
import subprocess

file = "/home/ye/Desktop/ss.json"
url = "http://www.ishadowsocks.com/"
pIdx = "C"

obj = urllib.request.urlopen(url)
content = obj.read().decode("utf8")

matcher = re.compile(r"([ABC])密码:(.*?)<")

passwd = {m.group(1): m.group(2) for m in matcher.finditer(content)}
print(passwd)

try:
    with open(file, "r") as f:
        data = json.load(f)
        data['password'] = passwd[pIdx]

    with open(file, "w") as f:
        json.dump(data, f)
except IOError:
    pass

args = ['sslocal', '-c', file]
cmd = "sslocal -c " + file
subprocess.run(args)
