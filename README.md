# EyeOftheSky

### 简介

* “天眼”是一个基于Qt搭建的监控视频识别系统，可扩展连接数据库，实现多用户管理、通过网络传输视频流、实时识别、读取二维码等。
* 技术栈：`C++ + Qt + JQQRCode`
* 优势：对服务器的性能占用小，移植开发板后的发热量小，适合小规模的监控视频识别方面的需求。识别响应时间在3ms内。
* 应用场景：可作为嵌入式开发板上位程序，配合电机、门闸搭建一套识别健康码的门禁系统。或各类需要验证身份的使用场景，也可当作家庭监控使用。

### 待添加功能

* 使用百度AI的api，可搭建车牌识别系统。
* 与esp32-cam配合，添加人脸识别功能。
* 连接数据库，实现多用户使用。针对不同用户给予不同的摄像头权限。
* 用户界面管理。

### 使用手册

登录界面：

![](https://raw.githubusercontent.com/HiKydin/Gallery/main/%E7%99%BB%E5%BD%95%E9%A1%B5%E9%9D%A2.jpg)

默认账号`admin`，密码`admin`。拥有所有摄像头权限。

登录成功后会自动扫描本机所连接的所有有线摄像头，并在左侧列出，用户点击即可访问特定的摄像头。

![](https://raw.githubusercontent.com/HiKydin/Gallery/main/%E7%95%8C%E9%9D%A21.jpg)

点击快照，可将实时画面捕捉并以截图方式保存本地计算机。

点击扫描二维码，开启扫描功能

![](https://raw.githubusercontent.com/HiKydin/Gallery/main/%E7%95%8C%E9%9D%A22.jpg)

![](https://raw.githubusercontent.com/HiKydin/Gallery/main/%E7%95%8C%E9%9D%A23.jpg)

识别速度在3ms内，注意二维码要正对，否则无法识别，识别成功后会在左侧显示识别到的二维码，同时读取其内容。
