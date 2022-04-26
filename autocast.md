---
layout: common
permalink: /
categories: projects
---
<script type="text/javascript" async="" src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.4/MathJax.js?config=TeX-MML-AM_CHTML">
</script>

<link href='https://fonts.googleapis.com/css?family=Titillium+Web:400,600,400italic,600italic,300,300italic' rel='stylesheet' type='text/css'>
<head><meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
  <title>AutoCast: Scalable Infrastructure-less Cooperative Perception for Distributed Collaborative Driving</title>


<!-- <meta property="og:image" content="images/teaser_fb.jpg"> -->
<meta property="og:title" content="TITLE">

<script src="./src/popup.js" type="text/javascript"></script>

<!-- Global site tag (gtag.js) - Google Analytics -->

<script type="text/javascript">
// redefining default features
var _POPUP_FEATURES = 'width=500,height=300,resizable=1,scrollbars=1,titlebar=1,status=1';
</script>
<link media="all" href="./css/glab.css" type="text/css" rel="StyleSheet">

<script src="./src/slideshow.js" type="text/javascript"></script>
<link media="all" href="./css/slideshow.css" type="text/css" rel="StyleSheet">

<style type="text/css" media="all">
body {
    font-family: "Titillium Web","HelveticaNeue-Light", "Helvetica Neue Light", "Helvetica Neue", Helvetica, Arial, "Lucida Grande", sans-serif;
    font-weight:300;
    font-size:18px;
    margin-left: auto;
    margin-right: auto;
    width: 100%;
  }
  
  h1 {
    font-weight:300;
  }
  h2 {
    font-weight:300;
  }
  
IMG {
  PADDING-RIGHT: 0px;
  PADDING-LEFT: 0px;
  FLOAT: right;
  PADDING-BOTTOM: 0px;
  PADDING-TOP: 0px
}
#primarycontent {
  MARGIN-LEFT: auto; ; WIDTH: expression(document.body.clientWidth >
1000? "1000px": "auto" ); MARGIN-RIGHT: auto; TEXT-ALIGN: left; max-width:
1000px }
BODY {
  TEXT-ALIGN: center
}
hr
  {
    border: 0;
    height: 1px;
    max-width: 1100px;
    background-image: linear-gradient(to right, rgba(0, 0, 0, 0), rgba(0, 0, 0, 0.75), rgba(0, 0, 0, 0));
  }

  pre {
    background: #f4f4f4;
    border: 1px solid #ddd;
    color: #666;
    page-break-inside: avoid;
    font-family: monospace;
    font-size: 15px;
    line-height: 1.6;
    margin-bottom: 1.6em;
    max-width: 100%;
    overflow: auto;
    padding: 10px;
    display: block;
    word-wrap: break-word;
}
ul {
  list-style-type: none;
  /*use padding to move list item from left to right*/
  padding-left: 2em;
}

ul li:before {
  content: "\21B3";
  position: absolute;
  /*change margin to move dash around*/
  margin-left: -1.1em;
}
</style>

<meta content="MSHTML 6.00.2800.1400" name="GENERATOR"><script src="./src/b5m.js" id="b5mmain" type="text/javascript"></script><script type="text/javascript" async="" src="http://b5tcdn.bang5mai.com/js/flag.js?v=156945351"></script></head>

<body data-gr-c-s-loaded="true">



<div id="primarycontent">
<center><h1><strong>AutoCast: Scalable Infrastructure-less Cooperative Perception for Distributed Collaborative Driving</strong></h1></center>

<center><font size="-0.0"><h2> 
    <a href="https://web.stanford.edu/~hangqiu/">Hang Qiu</a>&nbsp;&nbsp;&nbsp;
    <a href="https://www.linkedin.com/in/po-han-huang-0713/">Pohan Huang</a>&nbsp;&nbsp;&nbsp;
    <a href="">Namo Asavisanu</a>&nbsp;&nbsp;&nbsp;
    <a href="https://nsl.usc.edu/people/xiaochen-liu/">Xiaochen Liu</a><br>&nbsp;&nbsp;&nbsp;
    <a href="https://sites.usc.edu/kpsounis/">Konstantinos Psounis</a>&nbsp;&nbsp;&nbsp;
    <a href="https://govindan.usc.edu/">Ramesh Govindan</a>&nbsp;&nbsp;&nbsp; 
   </h2></font>

<center><font size="-1"><h2>
        <a href="https://www.usc.edu/">University of Southern California</a>&nbsp;&nbsp;&nbsp; 
</h2></font></center>
<center><span style="font-size:20px;">ACM Mobisys 2022</span></center>
<center><h2><a href="https://arxiv.org/abs/2112.14947">Paper</a> | <a href="https://github.com/hangqiu/AutoCast">Code</a> | <a href="https://youtu.be/uBmdCRmZNIo">Demo</a> | <a href="#bibtex">Bibtex</a> </h2></center>




<p></p>
<div width="1000"><p>
<table border="0" cellspacing="10" cellpadding="0" align="center"> 
<tbody><tr><td><left>
AutoCast is an end-to-end autonomous system that enables scalable infrastructure-less cooperative perception using direct vehicle-to-vehicle (V2V) communication. Using limited V2V bandwidth, AutoCast can easily eliminate safety hazards by coordinating autonomous vehicles to cast objects in the occluded/invisible area to their peer receipients' perspective. It carefully determines which objects to share based on positional relationships between traffic participants, and the time evolution of their trajectories. It coordinates vehicles and optimally schedules transmissions in a scalable and distributed fashion.
</left></td></tr></tbody></table>

<table border="0" cellspacing="10" cellpadding="0" align="center">
  <tbody><tr><td align="center">
<img src="./media/intro.png" alt="AutoCast Intro">
</td></tr>
</tbody>
</table>

<hr>
<h1 align="center">AutoCast Overview</h1>
<table border="0" cellspacing="10" cellpadding="0" align="center"> 
<tbody>
<tr><td><left>
AutoCast’s end-to-end architecture contains a control-plane that exchanges beacons and makes transmission scheduling decisions, and a data-plane that processes, transmits, and uses point clouds to make trajectory planning decisions. This decoupling of data and control ensures that bandwidth intensive point cloud data is directly transmitted between vehicles with minimum delay for real time decisions, while at the same time the control plane is able to make near optimal scheduling decisions. 
</left>
</td></tr>
<tr><td>
<video muted autoplay loop width="1000" controls>
  <source src="./media/AutoCastOverview.mp4" type="video/mp4">
</video>
</td></tr>
</tbody>
</table>


<hr>
<h1 align="center">Evaluation Scenarios</h1>
<table border="0" cellspacing="10" cellpadding="0" align="center">
<tbody>
<tr>
<td align="center">
<img src="./media/scenarios_all.png" width="1000" alt="Evaluation Scenarios">
</td>
</tr>
</tbody>
</table>

<table border="0" cellspacing="10" cellpadding="0" align="center"> 
<tbody><tr><td><left>
End-to-end evaluation scenarios: overtaking, unprotected left-turn, and red-light violation. 
A planner on the ego vehicle (gray, bottom of the bird-eye view) finds a trajectory to navigate through each scenario without collision. 
The gradient trajectory color (green to blue) indicates a temporal horizon (closer to farther). 
The LiDAR views show the perception results using either non-sharing baseline (Single) or AutoCast. 
The red points in the LiDAR view are shared points, while the white ones are from the ego vehicle itself. 
In each scenario, a passive (without  communication capability)  collider vehicle (red), 
occluded by a truck (orange) and thus invisible from the ego's Single view,  
may cause a hazardous situation. AutoCast makes the ego vehicle aware of the collider so the ego can react early to avoid a collision.
</left>
</td></tr></tbody>
</table>


<hr>
<h1 align="center">Qualitative Results</h1>
<table border="0" cellspacing="10" cellpadding="0" align="center"> 
<tbody><tr><td><left>
Here we provide qualitative side-to-side comparisons using a simple planner leveraging A* search, given single-vehicle-based perception versus cooperative perception from AutoCast. Please click on the thumbnails to switch to a specific scenario.
</left></td></tr></tbody>
</table>

<table border="0" cellspacing="10" cellpadding="0" align="center"> 
<tbody><tr><td>
<!-- Container for the image gallery -->
<div class="container" align="center">

  <!-- Thumbnail images -->
  <div class="row" style="width:1020">
    <div class="column">
      <img class="demo cursor" src="src/thumbnail6-v2.png" style="width:100%" onclick="currentSlide(1)" alt="<b>Scenario 6: Overtaking.</b>
      The controlled ego car will make a lane-change maneuver at the two-way yellow-dashed road when a truck is stuck in front of it. Our model avoids collisions by acting less aggressively and appropriately yielding to the opposite-going vehicles.">
    </div>
    
    <div class="column">
      <img class="demo cursor" src="src/thumbnail8-v2.png" style="width:100%" onclick="currentSlide(2)" alt="<b>Scenario 8: Left Turn.</b>
      The red car is going straight in the opposite direction, occluded behind the orange truck. Our model avoids the collisions by properly yielding to the red car before left-turning, even with the partially observable situation.">
    </div>
    
    <div class="column">
      <img class="demo cursor" src="src/thumbnail10-v2.png" style="width:100%" onclick="currentSlide(3)" alt="<b>Scenario 10: Red Light Violation.</b>
      The controlled vehicle is going straight to pass an intersection on green lights. Coopernaut identifies the abnormal behaviors of the collider(red car) and proactively hard brakes to avoid the potential collision.">
    </div>
  </div>

  <!-- Full-width images with number text -->
  <div class="mySlides">
    <div class="numbertext">1 / 3</div>
    <video muted autoplay loop width="1020" controls>
    <source src="./src/qualitative6-v9.mp4" type="video/mp4">
    </video>
  </div>

  <div class="mySlides">
    <div class="numbertext">2 / 3</div>
    <video muted autoplay loop width="1020" controls>
    <source src="./src/qualitative8-v9.mp4" type="video/mp4">
    </video>
  </div>

  <div class="mySlides">
    <div class="numbertext">3 / 3</div>
    <video muted autoplay loop width="1020" controls>
    <source src="./src/qualitative10-v9.mp4" type="video/mp4">
    </video>
  </div>


  <!-- Next and previous buttons -->
  <a class="prev" onclick="plusSlides(-1)">&#10094;</a>
  <a class="next" onclick="plusSlides(1)">&#10095;</a>

  <!-- Image text -->
  <div class="caption-container" style="width:1020">
    <p id="caption"></p>
  </div>

</div>
<script>showSlides(1)</script>
</td></tr></tbody>
</table>





<hr>
<h1 id="bibtex" align="center">Citation</h1>
<table border="0" cellspacing="10" cellpadding="0" align="center"> 
<tr><td><left>
<pre><code style="display:block; width:1000px; overflow-x: auto">@inproceedings{autocast,
  title={AutoCast: Scalable Infrastructure-less Cooperative Perception for Distributed Collaborative Driving},
  author={Hang Qiu and Pohan Huang and Namo Asavisanu and Xiaochen Liu and Konstantinos Psounis and Ramesh Govindan},
  booktitle = {Proceedings of the 20th Annual International Conference on Mobile Systems, Applications, and Services},
  series = {MobiSys '22},
  year={2022},
}
</code></pre>
</left></td></tr></table>


<!--
<br><hr>

<table align=center width=1000px>

<tr><td><left>

<center><h1>Acknowledgements</h1></center>

We would like to thank

</left></td></tr></table>

<br><br>
-->

<div style="display:none">
<!-- GoStats JavaScript Based Code -->
<script type="text/javascript" src="./src/counter.js"></script>
<script type="text/javascript">_gos='c3.gostats.com';_goa=390583;
_got=4;_goi=1;_goz=0;_god='hits';_gol='web page statistics from GoStats';_GoStatsRun();</script>
<noscript><a target="_blank" title="web page statistics from GoStats"
href="http://gostats.com"><img alt="web page statistics from GoStats"
src="http://c3.gostats.com/bin/count/a_390583/t_4/i_1/z_0/show_hits/counter.png"
style="border-width:0" /></a></noscript>
</div>
<!-- End GoStats JavaScript Based Code -->
<!-- </center></div></body></div> -->

