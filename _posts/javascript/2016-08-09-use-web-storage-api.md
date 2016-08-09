---
layout: article
title:  "使用 Web Storage API"
date:   16-8-9 下午4:46
categories: javascript
toc: true
tags:
  - javascript
  - webStorage
  - localStorage
  - sessionStorage
---

>简介：Web Storage API 提供了存储机制，通过该机制，浏览器可以安全地存储键值对，比使用 cookie 更加直观。这篇文章一步一步讲解如何使用这项简单的技术。

## 1、基本概念
Web Storage 包含如下两种机制：

* [sessionStorage](https://developer.mozilla.org/zh-CN/docs/Web/API/Window/sessionStorage) 为每一个给定的源（given origin）维持一个独立的存储区域，该存储区域在页面会话期间可用（即只要浏览器处于打开状态，包括页面重新加载和恢复）。
* [localStorage](https://developer.mozilla.org/zh-CN/docs/Web/API/Window/localStorage) 同样的功能，但是在浏览器关闭，然后重新打开后数据仍然存在。

这两种机制是通过 Window.sessionStorage 和 Window.localStorage 属性使用（更确切的说，在支持的浏览器中 Window 对象实现了 WindowLocalStorage 和 WindowSessionStorage 对象并挂在其 localStorage 和 sessionStorage 属性下）—— 调用其中任一对象会创建 Storage 对象，通过 Storage 对象，可以设置、获取和移除数据项。对于每个源（origin）sessionStorage 和 localStorage 使用不同的 Storage 对象——独立运行和控制。

例如，在文档中调用 localStorage 将会返回一个 Storage 对象；调用 sessionStorage 返回一个不同的 Storage 对象。可以使用相同的方式操作这些对象，但是操作是独立的。

## 2、Web Storage 接口

#### [Storage](https://developer.mozilla.org/zh-CN/docs/Web/API/Storage)
* 允许你在一个特定域中设置，检索和删除数据和储存类型(session or local.)

Storage             |类型 |解释
|-|-|
Storage.length      |属性 |只读,返回一个整数，表示存储在 Storage 对象中的数据项数量。
Storage.key()       |方法 |该方法接受一个数值 n 作为参数，并返回存储中的第 n 个键名
Storage.getItem()   |方法 |该方法接受一个键名作为参数，返回键名对应的值
Storage.setItem()   |方法 |该方法接受一个键名和值作为参数，将会把键值对添加到存储中，如果键名存在，则更新其对应的值
Storage.removeItem()|方法 |该方法接受一个键名作为参数，并把该键名从存储中删除
Storage.clear()     |方法 |调用该方法会清空存储中的所有键名

{% highlight js %}
//语法
var aLength     = storage.length;
var aKeyName    = storage.key(key);
var aValue      = storage.getItem(keyName);
storage.setItem(keyName, keyValue);
storage.removeItem(keyName);
storage.clear();
//示例
function populateStorage() {
    localStorage.setItem('bgcolor', 'yellow');
    localStorage.setItem('font', 'Helvetica');
    localStorage.setItem('image', 'cats.png');
    localStorage.length; // 返回 3
    localStorage.key(2); // 应该返回 'image'
    localStorage.removeItem('image'); // 把 image 数据项移除
    storage.clear(); // 把剩余 bgcolor,font 数据项移除
}

function setStyles() {
  var currentColor = localStorage.getItem('bgcolor');
  var currentFont = localStorage.getItem('font');
  var currentImage = localStorage.getItem('image');

  document.getElementById('bgcolor').value = currentColor;
  document.getElementById('font').value = currentFont;
  document.getElementById('image').value = currentImage;

  htmlElem.style.backgroundColor = '#' + currentColor;
  pElem.style.fontFamily = currentFont;
  imgElem.setAttribute('src', currentImage);
}
{% endhighlight %}

#### [Window](https://developer.mozilla.org/zh-CN/docs/Web/API/Window)
* Web Storage API 继承于Window 对象,并提供两个新属性  — Window.sessionStorage 和 Window.localStorage — 它们分别地提供对当前域的会话和本地Storage 对象的访问。

#### [StorageEvent](https://developer.mozilla.org/zh-CN/docs/Web/API/StorageEvent)
* 当一个存储区更改时，存储事件从文档的 Window 对象上被解除。

属性|类型|解释
|-|-|-|
key         |DOMString      |Represents the key changed. The key attribute is null when the change is caused by the storage clear() method. Read only.
newValue    |DOMString      |The new value of the key. The newValue is null when the change has been invoked by storage clear() method or the key has been removed from the storage. Read only.
oldValue    |DOMString      |The original value of the key. The oldValue is null when the change has been invoked by storage clear() method or the key has been newly added and therefor doesn't have any previous value. Read only.
storageArea |nsIDOMStorage  |Represents the Storage object that was affected. Read only.
url         |DOMString      |The URL of the document whose key changed. Read only.

方法|解释
|-|-|
initStorageEvent()|Initializes the event in a manner analogous to the similarly-named method in the DOM Events interfaces.

{% highlight js %}
void initStorageEvent(
  in DOMString typeArg,
  in boolean canBubbleArg,
  in boolean cancelableArg,
  in DOMString keyArg,
  in DOMString oldValueArg,
  in DOMString newValueArg,
  in DOMString urlArg,
  in nsIDOMStorage storageAreaArg
);

window.addEventListener('storage', function(e) {  
  document.querySelector('.my-key').textContent = e.key;
  document.querySelector('.my-old').textContent = e.oldValue;
  document.querySelector('.my-new').textContent = e.newValue;
  document.querySelector('.my-url').textContent = e.url;
  document.querySelector('.my-storage').textContent = e.storageArea;
});
{% endhighlight %}

## 3、浏览器的兼容性

Feature|Chrome|Firefox (Gecko)|Internet Explorer|Opera|Safari (WebKit)
|-|-|-|-|-|-|
localStorage    |4  |3.5    |8  |10.50  |4
sessionStorage  |5  |2      |8  |10.50  |4

## 4、低版本浏览器的方案
>需要用到 `cookie`，`IE6-7`下有效
{% highlight js %}
if (!window.localStorage) {
  window.localStorage = {
    getItem: function (sKey) {
      if (!sKey || !this.hasOwnProperty(sKey)) { return null; }
      return unescape(document.cookie.replace(new RegExp("(?:^|.*;\\s*)" + escape(sKey).replace(/[\-\.\+\*]/g, "\\$&") + "\\s*\\=\\s*((?:[^;](?!;))*[^;]?).*"), "$1"));
    },
    key: function (nKeyId) {
      return unescape(document.cookie.replace(/\s*\=(?:.(?!;))*$/, "").split(/\s*\=(?:[^;](?!;))*[^;]?;\s*/)[nKeyId]);
    },
    setItem: function (sKey, sValue) {
      if(!sKey) { return; }
      document.cookie = escape(sKey) + "=" + escape(sValue) + "; expires=Tue, 19 Jan 2038 03:14:07 GMT; path=/";
      this.length = document.cookie.match(/\=/g).length;
    },
    length: 0,
    removeItem: function (sKey) {
      if (!sKey || !this.hasOwnProperty(sKey)) { return; }
      document.cookie = escape(sKey) + "=; expires=Thu, 01 Jan 1970 00:00:00 GMT; path=/";
      this.length--;
    },
    hasOwnProperty: function (sKey) {
      return (new RegExp("(?:^|;\\s*)" + escape(sKey).replace(/[\-\.\+\*]/g, "\\$&") + "\\s*\\=")).test(document.cookie);
    }
  };
  window.localStorage.length = (document.cookie.match(/\=/g) || window.localStorage).length;
}
{% endhighlight %}