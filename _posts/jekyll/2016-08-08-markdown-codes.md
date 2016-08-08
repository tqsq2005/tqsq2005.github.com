---
layout: article
title:  "Jekyll中Markdown常用代码段"
date:   16-8-8 下午2:48
categories: jekyll
tags:
  - jekyll
  - 代码段
toc: true
---

>简介：Jekyll中Markdown常用代码段

## 1、提示™、说明以及警告
{% highlight html %}
<div class="note">
  <h5>提示™帮助你更好的使用 Jekyll</h5>
  <p>这儿有各种小技巧让你成为 Jekyll 的魔法师</p>
</div>

<div class="note info">
  <h5>说明包含一些有用的信息</h5>
  <p>这儿提供一些帮助理解 Jekyll 的其他内容</p>
</div>

<div class="note warning">
  <h5>警告帮助你不出错</h5>
  <p>如果不想出错，请注意这类消息</p>
</div>

<div class="note unreleased">
  <h5>尚未发布的功能</h5>
  <p>这部分内容针对 Jekyll 尚未发布的版本</p>
</div>
{% endhighlight %}

<div class="note">
  <h5>提示™帮助你更好的使用 Jekyll</h5>
  <p>这儿有各种小技巧让你成为 Jekyll 的魔法师</p>
</div>

<div class="note info">
  <h5>说明包含一些有用的信息</h5>
  <p>这儿提供一些帮助理解 Jekyll 的其他内容</p>
</div>

<div class="note warning">
  <h5>警告帮助你不出错</h5>
  <p>如果不想出错，请注意这类消息</p>
</div>

<div class="note unreleased">
  <h5>尚未发布的功能</h5>
  <p>这部分内容针对 Jekyll 尚未发布的版本</p>
</div>

## 2、高亮代码片段
{% highlight text %}
{% raw %}{% highlight ruby %}{% endraw %}
def show
  @widget = Widget(params[:id])
  respond_to do |format|
    format.html # show.html.erb
    format.json { render json: @widget }
  end
end
{% raw %}{% endhighlight %}{% endraw %}
{% endhighlight %}

将输出下面的效果：

{% highlight ruby %}
def show
  @widget = Widget(params[:id])
  respond_to do |format|
    format.html # show.html.erb
    format.json { render json: @widget }
  end
end
{% endhighlight %}

<div class="note">
  <h5>提示™：显示行数</h5>
  <p>
    你可以在代码片段中增加关键字 <code>linenos</code> 来显示行数。这样完整的高亮开始标记将会是: <code>{% raw %}{% highlight ruby linenos %}{% endraw %}</code>。
  </p>
</div>

## 3、常用代码高亮语言
{% highlight text %}
text
html
js
php
mysql
python
{% endhighlight %}
本博客使用 [Pygments](http://pygments.org) 实现代码高亮，`Pygments` 支持超过 [一百种语言](http://pygments.org/languages/)。可以在 [Pygments’ Lexers page](http://pygments.org/docs/lexers/) 寻找对应语言的 “short name”。

## 4、链接
{% highlight text %}
[关于我](/about)
{% endhighlight %}
[关于我](/about)

## 5、博文链接（Post URL）
如果你想使用你某篇文章的链接，标签 `post_url` 可以满足你的需求。

{% highlight text %}
{% raw %}
{% post_url 2010-07-21-name-of-post %}
{% endraw %}
{% endhighlight %}

如果你使用了子文件夹来组织你的博文，你需要在路径中加入子文件夹：

{% highlight text %}
{% raw %}
{% post_url /subdir/2010-07-21-name-of-post %}
{% endraw %}
{% endhighlight %}

当使用`post_url`标签时，不需要写文件后缀名。

还可以用 Markdown 这样为你的文章生成超链接：

{% highlight text %}
{% raw %}
[Name of Link]({% post_url 2010-07-21-name-of-post %})
{% endraw %}
{% endhighlight %}

## 6、引用图片和其它资源
在文章中引用一个图片

{% highlight text %}
… 从下面的截图可以看到：
![有帮助的截图]({% raw %}{{ site.url }}{% endraw %}/assets/screenshot.jpg)
{% endhighlight %}

链接一个读者可下载的 PDF 文件：

{% highlight text %}
… 你可以直接 [下载 PDF]({% raw %}{{ site.url }}{% endraw %}/assets/mydoc.pdf).
{% endhighlight %}

<div class="note">
  <h5>提示™：链接只使用站点的根 URL</h5>
  <p>
    如果你<strong>确信</strong>你的站点只在域名的根 URL 下做展示，你可以不使用 <code>{% raw %}{{ site.url }}{% endraw %}</code> 变量。在这种情况下，直接使用 <code>/path/file.jpg</code> 即可。
  </p>
</div>

## 7、使用 font-awesome
{% highlight html %}
<b>
<i class="fa fa-tags"/>
Tag | 标签：
</b>
{% endhighlight %}

<b>
<i class="fa fa-tags"/>
Tag | 标签：
</b>