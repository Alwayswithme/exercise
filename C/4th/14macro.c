/** 
 * 定义宏swap(t, x, y) 以交换t类型的两个参数.(使用程序结构)
 */
#define swap(t, x, y) { t _z; \
                        _z = y; \
                        y = x;  \
                        x = _z;}
