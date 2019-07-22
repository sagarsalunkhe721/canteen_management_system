<%@page import="com.canteenDB.cms.dto.User"%>
<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
	pageEncoding="ISO-8859-1"%>

<%
	User user = (User) session.getAttribute("user");
%>
<!DOCTYPE html>
<html>
<head>
<script src="https://ajax.googleapis.com/ajax/libs/jquery/3.2.1/jquery.min.js"></script>
<script>

$(document).ready(function(){
   
   $('#hii').load("report_list.jsp");

});
</script>
<link rel="stylesheet"
	href="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/css/bootstrap.min.css">
<script
	src="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/js/bootstrap.min.js"></script>
<link rel="stylesheet" href="css/style.css">
<meta charset="ISO-8859-1">
<title>Admin Home</title>


</head>
<body>
	<div class="container-fluid">
		<div class="row bg-dark">
			<nav class="navbar navbar-expand-lg bg-dark">
				<a class="navbar-brand" href="home.jsp">CDAC CANTEEN</a>
				<div class="collapse navbar-collapse" id="navbarNavAltMarkup">
					<div class="navbar-nav">
						<a class="nav-item nav-link active" href="item_list.htm">Items</a> 
						<a class="nav-item nav-link"
							href="course_list.htm">Course</a> 
						<a class="nav-item nav-link" href="department_list.htm">Departments</a>
						<a class="nav-item nav-link" href="person_list.htm">Person</a>
						<a class="nav-item nav-link" href="guest_list.htm">Guest</a>
						<a class="nav-item nav-link" href="supervisor/supervisor.jsp">Supervisor</a>
						<div id="hii"> </div>
					<!-- 
						<select name="Reports" class="text-primary bg-dark "  style="border: none;">
						<option>Reports</option>
						<option>Item</option>
    					<option>Person</option>
    					<option>Performance</option>
    					<option>Official Guest</option>
    					<option>Guest</option>
						</select>  -->
								
			
						
					</div>
				</div>
			</nav>
		</div>
	</div>
</body>
</html>