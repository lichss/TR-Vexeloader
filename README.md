# V-ProcessRunner





## 12-5提交记录

程序先检查.ini文件，没有的话会弹提示。
.ini文件需要指定要启动的是哪一个程序




示例：
```
[Application]
Mode=Adams
; 可选项： 'Adams' 、 'UGS' 、'Ansys' 
```
ini文件读取的变量名在[processcmdset.h](include\processcmdset.h)中定义，可以通过宏定义修改。
默认：

``` C++
#define ADAMS_PROCESS_MODE	"Adams"
#define UGS_PROCESS_MODE	"UGS"
#define ANSYS_PROCESS_MODE	"Ansys"
```

之后检查环境变量来确定文件路径。

可以通过 [processcmdset.h](include\processcmdset.h)的宏定义来改变环境变量的名称。

默认：
``` C++
#define ADAMS_ENVIR_KEY "ADAMS_LAUNCH_PATH"
#define UGS_ENVIR_KEY "UGS_LAUNCH_PATH"
#define ANSYS_ENVIR_KEY "ANSYS_LAUNCH_PATH"
```


附带一个示例[config.ini](config.ini)config.ini文件：
