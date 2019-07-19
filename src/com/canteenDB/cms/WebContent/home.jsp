<%@page import="com.canteenDB.cms.dto.User"%>
<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
	pageEncoding="ISO-8859-1"%>

<%
	User user = (User) session.getAttribute("user");
%>
<!DOCTYPE html>
<html>
<head>
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
				<a class="navbar-brand" href="#">CDAC CANTEEN</a>
				<div class="collapse navbar-collapse" id="navbarNavAltMarkup">
					<div class="navbar-nav">
						<a class="nav-item nav-link active" href="item_list.htm">Items <span
							class="sr-only">(current)</span></a> 
						<a class="nav-item nav-link"
							href="#">Course</a> 
						<a class="nav-item nav-link" href="#">Departments</a>
						<a class="nav-item nav-link active" href="person_list.htm">Person<span
						 class="sr-only">(current)</span></a>
						<a class="nav-item nav-link" href="#">Guest</a>
					</div>
				</div>
			</nav>
		</div>
	</div>
</body>
</html>