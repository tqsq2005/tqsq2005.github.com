---
layout: article
title:  "CSS平时遇到的问题汇总"
date:   2016-08-07 17:45:10
categories: csshtml
toc: true
---

>简介：本文主要记录平时遇到的CSS问题

## 1、IE环境下，网页导出`excel`时`身份证号`等`长数字格式`自动转为科学计数法
{% highlight css%}
{% raw %}
.exportExcel{
    mso-number-format:'\@';
}
{% endraw %}
{% endhighlight %}

## 2、`网页`显示但`打印的时候`不显示
{% highlight css%}
{% raw %}
<style media="print" type="text/css">
.noPrint{
    display: 'none';
}
</style>
{% endraw %}
{% endhighlight %}
