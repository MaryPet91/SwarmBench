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
<title></title>
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

	<%
	String att = (String) request.getAttribute("namefile");
	String param = (String) request.getAttribute("parameter");
	%>
	    <div id="wrapper">

        <!-- Navigation -->
        <nav class="navbar navbar-default navbar-static-top" role="navigation" style="margin-bottom: 0">
            <div class="navbar-header">
                <button type="button" class="navbar-toggle" data-toggle="collapse" data-target=".navbar-collapse">
                    <span class="sr-only">Toggle navigation</span>
                    <span class="icon-bar"></span>
                    <span class="icon-bar"></span>
                    <span class="icon-bar"></span>
                </button>
                <a class="navbar-brand" href="HomePage.jsp">SPIN Swarm vs. Lazy-CSeq Swarm</a>
            </div>
            <!-- /.navbar-header -->


	<!-- MENU LATERALE -->
				 
            <div class="navbar-default sidebar" role="navigation">
                <div class="sidebar-nav navbar-collapse">
                    <ul class="nav" id="side-menu"> 
<li>
                            <a href="SPINFiles.jsp"><i class="fa fa-files-o fa-fw"></i> Swarm SPIN</a>
                        </li>
                        <li>
                            <a href="LazyCSeqFiles.jsp"><i class="fa fa-files-o fa-fw"></i> Swarm Lazy-CSeq</a>
                        </li>
                        <li>
                            <a href="TablesResults.jsp"><i class="fa fa-table fa-fw"></i> Tables results</a>
                        </li>
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
				<h1 class="page-header">Swarm benchmark</h1>
			</div>
			<!-- /.col-lg-12 -->
		</div>
		<!-- /.row -->
		<div class="row">
			<div class="col-lg-12">
				<div class="panel panel-default">
					<div class="panel-heading">Continue</div>
					<div class="panel-body">
						<div class="row">
							<div class="col-lg-6">
								<form action="StoreSpinJSON" method="get">

									<input type="hidden" name="namefile" value="<%=att%>">
									<input type = "hidden" name="param" value = "<%=param%>">
									<button type="submit" class="btn btn-outline btn-success">Proceed</button>
								</form>

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
		<!-- /.row -->
	</div>
	<!-- /#page-wrapper -->



</body>
</html>