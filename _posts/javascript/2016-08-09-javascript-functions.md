---
layout: article
title:  "Javascript遇到的函数"
date:   16-8-9 下午4:46
categories: javascript
toc: true
tags:
  - javascript
  - codes
  - function
---

>简介：记录Javascript遇到的函数

## 1、document.querySelector()
返回当前文档中第一个匹配特定选择器的元素（使用深度优先，前序遍历规则遍历所有文档节点）。[more](https://developer.mozilla.org/zh-CN/docs/Web/API/Document/querySelector#Browser_Compatibility)
IE8以上兼容，语法：`element = document.querySelector(selectors);`

<div class="note info">
  <h5>提示™</h5>
  <p>
    <code>element</code> 是一个 <code>element</code> 对象（DOM 元素）;<code>selectors</code> 是一个字符串，包含一个或是多个 <code>CSS</code> 选择器 ，多个则以逗号分隔。
  </p>
</div>