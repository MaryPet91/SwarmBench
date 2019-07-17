<%@page import="org.json.simple.JSONObject"%>
<%@page import="java.util.ArrayList"%>
<%@page import="org.json.simple.parser.JSONParser"%>
<%@page import="java.io.FileReader"%>
<%@page import="java.io.BufferedReader"%>
<%@page import="java.io.File"%>
<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
	pageEncoding="ISO-8859-1"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<meta http-equiv="X-UA-Compatible" content="IE=edge">
<meta name="viewport" content="width=device-width, initial-scale=1">
<meta name="description" content="">
<meta name="author" content="">
<title>Tables results</title>
<!-- Bootstrap Core CSS -->
<link href="vendor/bootstrap/css/bootstrap.min.css" rel="stylesheet">

<!-- MetisMenu CSS -->
<link href="vendor/metisMenu/metisMenu.min.css" rel="stylesheet">

<!-- Custom CSS -->
<link href="dist/css/sb-admin-2.css" rel="stylesheet">

<!-- Custom Fonts -->
<link href="vendor/font-awesome/css/font-awesome.min.css"
	rel="stylesheet" type="text/css">

<!-- HTML5 Shim and Respond.js IE8 support of HTML5 elements and media queries -->
<!-- WARNING: Respond.js doesn't work if you view the page via file:// -->
<!--[if lt IE 9]>
        <script src="https://oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js"></script>
        <script src="https://oss.maxcdn.com/libs/respond.js/1.4.2/respond.min.js"></script>
    <![endif]-->
<!-- jQuery -->
<script src="vendor/jquery/jquery.min.js"></script>

<!-- Bootstrap Core JavaScript -->
<script src="vendor/bootstrap/js/bootstrap.min.js"></script>

<!-- Metis Menu Plugin JavaScript -->
<script src="vendor/metisMenu/metisMenu.min.js"></script>

<!-- Custom Theme JavaScript -->
<script src="dist/js/sb-admin-2.js"></script>
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
	<div id="page-wrapper">
		<div class="row">
			<div class="col-lg-12">
				<h1 class="page-header">Tables results</h1>
			</div>
			<!-- /.col-lg-12 -->
		</div>
		<!-- /.row -->
		<div class="row">
			<div class="col-lg-12">
				<div class="panel panel-default">
					<div class="panel-body">
						<div class="row">
							<div class="col-lg-6">
								<h1>Swarm SPIN results</h1>
								
									<%
										File dir = new File("/home/mary/tacs/Swarm-Project/script/swarmBenchWS/SPIN/");
										File[] jsons = dir.listFiles();
									%>


									<table class="table table-striped table-bordered table-hover"
										id="resultSpin">
										<thead>
											<tr>
												<th>Program name</th>
												<th>Time (s)</th>
												<th>Memory Usage (MB)</th>
												<th>Parameters</th>

											</tr>
										</thead>
										<tbody>
											<%
												for (File f : jsons) {
													BufferedReader br = new BufferedReader(new FileReader(f));
													String read = "";
													while ((read = br.readLine()) != null) {
														
														JSONObject json = (JSONObject) new JSONParser().parse(read);
														
											%>

											<tr class="odd gradeX">
												<td>
													<%=json.get("nomeProgramma")
													%>
												</td>
												<td>
													<%=json.get("time")
													%>
												</td>
												<td>
													<%=json.get("memoryUsage")
													%>
												</td>
												<td>
													<%=json.get("params")
													%>
												</td>

											</tr>
											<%
												}
													br.close();
												}
											%>

										</tbody>
									</table>
								
							</div>


						</div>

						<!-- /.row (nested) -->
					</div>
					<!-- /.panel-body -->
				</div>
				<!-- /.panel -->
			</div>
			<!-- /.col-lg-12 -->
		</div>
		<!-- /.form SPIN -->

		<div class="row">
			<div class="col-lg-12">
				<div class="panel panel-default">
					<div class="panel-body">
						<div class="row">
							<div class="col-lg-6">
								<h1>Swarm Lazy-CSeq results</h1>
							

									<%
									File dir1 = new File("/home/mary/tacs/Swarm-Project/script/swarmBenchWS/Lazy-CSeq/");
									File[] jsons1 = dir1.listFiles();
									%>
									<table class="table table-striped table-bordered table-hover"
										id="resultSpin">
										<thead>
											<tr>
												<th>Program name</th>
												<th>Time (s)</th>
												<th>Memory Usage (MB)</th>
												<th>Parameters</th>

											</tr>
										</thead>
										<tbody>
											<%
												for (File f : jsons1) {
													BufferedReader br1 = new BufferedReader(new FileReader(f));
													String read1 = "";
													while ((read1 = br1.readLine()) != null) {
													
														JSONObject json1 = (JSONObject) new JSONParser().parse(read1);
														
											%>

											<tr class="odd gradeX">
												<td>
													<%=json1.get("nomeProgramma")
													%>
												</td>
												<td>
													<%=json1.get("time")
													%>
												</td>
												<td>
													<%=json1.get("memoryUsage")
													%>
												</td>
												<td>
													<%=json1.get("unwind")
													%>
												</td>

											</tr>
											<%
												}
													br1.close();
												}
											%>

										</tbody>
									</table>
								
								<div class="col-lg-12"
									style="text-align: center; margin-top: 7%;">
									<form action="SeePlots.jsp">
										<button type="submit" class="btn btn-success">See
											plots</button>
									</form>
								</div>
								<!-- BUTTON -->

							</div>
						</div>
						<!-- /.row (nested) -->
					</div>
					<!-- /.panel-body -->
				</div>
				<!-- /.panel -->
			</div>
			<!-- /.col-lg-12 -->
		</div>
		<!-- /.form Lazy-CSeq -->

		<!-- /.form plot -->
	</div>

</body>
</html>