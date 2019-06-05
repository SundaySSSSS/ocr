# ocr
目前仅支持windows平台
使用百度Ocr接口实现的文字识别工具  
调用的百度接口部分使用Python编写, Qt编写界面  

使用方法:
1, 安装pyinstaller, 用于将python脚本生成exe, 使用命令`pip install pyinstaller`  
2, 执行脚本createApi.cmd
3, 编译ui中的QT工程
4, 将申请的百度App id, api key, secret key存放到bin/key.txt中, 分三行存储, 例如:  
```
1561xxxx
U20XExICr60etvSpFHtxxxx
3WRVR0Lf1XdWhEbs66gRw5Zml8ufxxxx
```
