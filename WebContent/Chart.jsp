<%@page import="org.json.simple.JSONArray"%>
<%@page import="org.json.simple.parser.JSONParser"%>
<%@page import="org.json.simple.JSONObject"%>

<%@page import="java.util.ArrayList"%>
<%@page import="java.io.File"%>
<%@page import="java.io.FileReader"%>
<%@page import="java.io.BufferedReader"%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">



<script src="https://code.highcharts.com/highcharts.js"></script>
<script src="https://code.highcharts.com/modules/series-label.js"></script>
<script src="https://code.highcharts.com/modules/exporting.js"></script>
<script src="https://code.highcharts.com/modules/export-data.js"></script>


<title>Benchmarks Result-Plots</title>
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
	<div class="row">
		<div class="col-lg-12">
			<h1 class="page-header" style="text-align: center;">Charts
				results</h1>
		</div>
		<!-- TITLE -->
	</div>

	<% File f = new File("/home/mary/tacs/Swarm-Project/script/swarmBenchWS/results/spin_mem_time.json"); 

	
	
	BufferedReader br = new BufferedReader(new FileReader(f));
	String read = "";
	String first = "";
	String second = "";
	String nameFile = "";
	ArrayList<String> datas = new ArrayList<>();
	
	while((read = br.readLine())!=null){
		 
		JSONObject json = (JSONObject) new JSONParser().parse(read);
		nameFile = json.get("name")+"";
		JSONArray array = (JSONArray)json.get("data");
		for(int i =0; i<array.size(); i++){
			String data = array.get(i)+"";
			data = data.substring(1, data.lastIndexOf("]"));
			String [] d = data.split(",");
			first = first+d[0]+", ";
			second = second+d[1]+", ";
			
		}
		
		first = first.substring(0, first.lastIndexOf(","));
		second = second.substring(0, second.lastIndexOf(","));
		datas.add(first);  //time
		datas.add(second); //memory
		
		System.out.println(datas.get(0));

		System.out.println(datas.get(1));
		
	%>

	<%	}
	
	br.close();
%>





	<div id="containerSPIN"
		style="min-width: 310px; height: 400px; margin: 0 auto"></div>


	<script type="text/javascript">


Highcharts.chart('containerSPIN', {
    chart: {
        type: 'spline'
    },
    title: {
        text: 'Swarm SPIN'
    },
    subtitle: {
        text: 'Results <%=nameFile.split("_")[2]%>'
    },
    xAxis: {
   	 title: {
            text: 'time'
        },
        categories: [<%=datas.get(0)%>]
    },
    yAxis: {
        title: {
            text: 'memory'
        }
    },
    tooltip: {
        crosshairs: true,
        shared: true
    },
    plotOptions: {
        spline: {
            marker: {
                radius: 4,
                lineColor: 'black',
                lineWidth: 1
            }
        }
    },
    series: [ {
        name: '<%=nameFile.split("_")[2]%>',
        data: [<%=datas.get(1)%>]}]
    
});

</script>


	<% File f1 = new File("/home/mary/tacs/Swarm-Project/script/swarmBenchWS/results/cseq_temp_mem.json"); 

	
	
	BufferedReader br1 = new BufferedReader(new FileReader(f1));
	String read1 = "";
	String first1 = "";
	String second1 = "";
	String nameFile1 = "";
	ArrayList<String> datas1 = new ArrayList<>();
	
	while((read1 = br1.readLine())!=null){
		 
		JSONObject json = (JSONObject) new JSONParser().parse(read1);
		nameFile = json.get("name")+"";
		JSONArray array = (JSONArray)json.get("data");
		for(int i =0; i<array.size(); i++){
			String data = array.get(i)+"";
			data = data.substring(1, data.lastIndexOf("]"));
			String [] d = data.split(",");
			first1 = first1+d[0]+", ";
			second1 = second1+d[1]+", ";
			
		}
		
		first1 = first1.substring(0, first1.lastIndexOf(","));
		second1 = second1.substring(0, second1.lastIndexOf(","));
		datas1.add(first1);  //time
		datas1.add(second1); //memory

	%>

	<%	}
	
	br1.close();
%>





	<div id="containerCSEQ"
		style="min-width: 310px; height: 400px; margin: 0 auto"></div>


	<script type="text/javascript">


Highcharts.chart('containerCSEQ', {
    chart: {
        type: 'spline'
    },
    title: {
        text: 'Swarm Lazy-CSeq'
    },
    subtitle: {
        text: 'Results <%=nameFile.split("_")[2]%>'
    },
    xAxis: {
    	 title: {
             text: 'time'
         },
        categories: [<%=datas1.get(0)%>]
    },
    yAxis: {
        title: {
            text: 'memory'
        }
    },
    tooltip: {
        crosshairs: true,
        shared: true
    },
    plotOptions: {
        spline: {
            marker: {
                radius: 4,
                lineColor: 'black',
                lineWidth: 1
            }
        }
    },
    series: [{
        name: '<%=nameFile.split("_")[2]%>',
        data: [<%=datas1.get(1)%>]}]
    
});

</script>

<div id="containerSPINCSEQ"
		style="min-width: 310px; height: 400px; margin: 0 auto"> </div>


	<script type="text/javascript">


Highcharts.chart('containerSPINCSEQ', {
	chart: {
        type: 'spline'
    },
    
    title: {
        text: 'Swarm SPIN vs. Swarm Lazy-CSeq'
    },
    subtitle: {
        text: 'Results <%=nameFile.split("_")[2]%>'
    },xAxis: {

   	 title: {
            text: 'time'
        },
        categories: [<%=datas1.get(0)%>]
    },
    yAxis: {
        title: {
            text: 'memory'
        }
    },
    
    series: [{
        name: '<%=nameFile.split("_")[2]+"_lazy-cseq"%>' ,
        data: [<%=datas1.get(1)%>]

        },{
            name: '<%=nameFile.split("_")[2]+"_spin"%>' ,
            data: [<%=datas.get(1)%>]

            }]
});

</script>



</body>




</html>
