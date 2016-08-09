---
layout: article
title:  "ubuntu下安装xampp"
date:   16-8-9 上午8:54
categories: php
tags:
  - ubuntu
  - xampp
toc: false
---

>简介：在ubuntu下安装xampp（apache、mysql 、php 、phpmyadmin）集成包

## 步骤如下
{% highlight bash %}
#安装
sudo ./xampp-linux-x64-1.8.3-4-installer.run
#运行
cd /opt/lampp/
sudo ./lampp start
#创建软链接
sudo ln -sf /opt/lampp/htdocs ~/htdocs
#关闭
cd /opt/lampp/
sudo ./lampp stop
#卸载
rm -rf /opt/lampp
{% endhighlight %}