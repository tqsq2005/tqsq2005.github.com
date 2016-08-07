---
layout: archive
permalink: /life/
title: "生活感想"
excerpt: "人生就是一场未知目的地的旅行，更多的时候，我们并不知道自己接下来会遇见怎样的未来。只不过有时候，我们只是一味的狂奔，却忘记了旅行的意义。"
---

<div class="tiles">
{% for post in site.posts %}
	{% if post.categories contains 'life' %}
		{% include post-grid.html %}
	{% endif %}
{% endfor %}
</div><!-- /.tiles -->
