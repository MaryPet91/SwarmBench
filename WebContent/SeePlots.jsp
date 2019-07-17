<%@page import="java.io.File"%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html lang="en">

<head>

<meta charset="utf-8">
<meta http-equiv="X-UA-Compatible" content="IE=edge">
<meta name="viewport" content="width=device-width, initial-scale=1">
<meta name="description" content="">
<meta name="author" content="">

<title>SPIN Swarm vs. Lazy-CSeq Swarm</title>

<!-- Bootstrap Core CSS -->
<link href="vendor/bootstrap/css/bootstrap.min.css" rel="stylesheet">

<!-- MetisMenu CSS -->
<link href="vendor/metisMenu/metisMenu.min.css" rel="stylesheet">

<!-- Custom CSS -->
<link href="dist/css/sb-admin-2.css" rel="stylesheet">

<!-- Morris Charts CSS -->
<link href="vendor/morrisjs/morris.css" rel="stylesheet">

<!-- Custom Fonts -->
<link href="vendor/font-awesome/css/font-awesome.min.css"
	rel="stylesheet" type="text/css">

<!-- HTML5 Shim and Respond.js IE8 support of HTML5 elements and media queries -->
<!-- WARNING: Respond.js doesn't work if you view the page via file:// -->
<!--[if lt IE 9]>
        <script src="https://oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js"></script>
        <script src="https://oss.maxcdn.com/libs/respond.js/1.4.2/respond.min.js"></script>
    <![endif]-->

</head>

<style>
body {
	font-family: "Times New Roman", Times, serif;
	color: black;
}

p {
	font-size: 120%;
}
</style>

<body>
	<div id="wrapper">

		<!-- Navigation -->
		<nav class="navbar navbar-default navbar-static-top" role="navigation"
			style="margin-bottom: 0">
			<div class="navbar-header">
				<button type="button" class="navbar-toggle" data-toggle="collapse"
					data-target=".navbar-collapse">
					<span class="sr-only">Toggle navigation</span> <span
						class="icon-bar"></span> <span class="icon-bar"></span> <span
						class="icon-bar"></span>
				</button>
				<a class="navbar-brand" href="HomePage.jsp">SPIN Swarm vs.
					Lazy-CSeq Swarm</a>
			</div>
			<!-- /.navbar-header -->


			<!-- MENU LATERALE -->

			<div class="navbar-default sidebar" role="navigation">
				<div class="sidebar-nav navbar-collapse">
					<ul class="nav" id="side-menu">
						<li><a href="SPINFiles.jsp"><i
								class="fa fa-files-o fa-fw"></i> Swarm SPIN</a></li>
						<li><a href="LazyCSeqFiles.jsp"><i
								class="fa fa-files-o fa-fw"></i> Swarm Lazy-CSeq</a></li>
						<li><a href="TablesResults.jsp"><i
								class="fa fa-table fa-fw"></i> Tables results</a></li>
					</ul>
				</div>
				<!-- /.sidebar-collapse -->
			</div>
			<!-- MENU LATERALE -->

		</nav>
		<!-- /#page-wrapper -->

	</div>
	<div id="wrapper">

		<div id="page-wrapper">
			<div class="row">
				<div class="col-lg-12">
					<h2 class="page-header" style="text-align: center;">Plots</h2>
				</div>
				<!-- TITLE -->
			</div>

			<%
				
				/*if (filesCSeq.length >= filesSPIN.length)
					size = filesSPIN.length;
				else
					size = filesCSeq.length;*/
			%>

			<form action="JSONtemp" method="get" target="_blank">


				<%
				
				File[] filesCSeq = new File("/home/mary/tacs/Swarm-Project/script/swarmBenchWS/Lazy-CSeq").listFiles();
				File[] filesSPIN = new File("/home/mary/tacs/Swarm-Project/script/swarmBenchWS/SPIN").listFiles();
				int size=filesCSeq.length;
					for (int i = 0; i < size; i++) {
						for (int j = 0; j < size; j++) {

							System.out.println("cseq- spin : "+filesCSeq[i].getName()+"-"+filesSPIN[j].getName()+" size:"+size);
							if (filesCSeq[i].getName().equals(filesSPIN[j].getName())) {
				%>
				<button type="submit" name="plot" class="btn btn-outline btn-primary btn-lg"
					value="<%=filesCSeq[i].getName()%>">
					
					<%=filesSPIN[j].getName().substring(0, filesSPIN[j].getName().lastIndexOf("."))%>
				</button>
				<%
					
							}
				%>

				<%
					}
					}
				%>
			</form>


		</div>
		<!-- /#page-wrapper -->

	</div>
	<!-- /#wrapper -->

	<!-- jQuery -->
	<script src="vendor/jquery/jquery.min.js"></script>

	<!-- Bootstrap Core JavaScript -->
	<script src="vendor/bootstrap/js/bootstrap.min.js"></script>

	<!-- Metis Menu Plugin JavaScript -->
	<script src="vendor/metisMenu/metisMenu.min.js"></script>

	<!-- Morris Charts JavaScript -->
	<script src="vendor/raphael/raphael.min.js"></script>
	<script src="vendor/morrisjs/morris.min.js"></script>
	<script src="data/morris-data.js"></script>

	<!-- Custom Theme JavaScript -->
	<script src="dist/js/sb-admin-2.js"></script>

</body>

</html>
