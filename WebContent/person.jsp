<%@page import="com.canteenDB.cms.dto.Person"%>
<%@page import="java.util.List"%>
<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
	pageEncoding="ISO-8859-1"%>

<%-- <%@ taglib uri="http://www.springframework.org/tags/form" prefix="spr"%> --%>
<%
	List<Person> personList = (List<Person>) request.getAttribute("ul");
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
<meta charset="ISO-8859-1">
<title>Persons</title>
<link rel="stylesheet"
	href="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/css/bootstrap.min.css">
<script
	src="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/js/bootstrap.min.js"></script>
<link rel="stylesheet" href="css/style.css">
</head>
<body>
	<div class="container-fluid">
		<div class="row bg-dark"
			style="height: 55px; position: sticky; top: 0; z-index: 9999;">
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
					</div>
				</div>
			</nav>
		</div>
		<div class="row d-flex make-center bg-secondary "
			style="height: 55px;">
			<div class="ml-3">
				<a class="btn btn-primary" href="prep_person_form.htm">Add Person</a>
			</div>
			<div class="ml-3">
				<input type="text" class="form-control rounded"
					placeholder="Search Person" />
			</div>
			<div class="ml-3">
				<input class="btn btn-success form-control rounded" type="submit"
					value="Search" />
			</div>
		</div>
		<table class="table table-striped table-bordered">
			<thead class="thead-dark">
				<tr>
					<th scope="col">Person Id</th>
					<th scope="col">Name</th>
					<th scope="col">Department Id</th>
					<th scope="col">Settlement Type</th>
					<th scope="col">Remark</th>
					<th scope="col">Delete</th>
					<th scope="col">Edit</th>
				</tr>
			</thead>
			<tbody>

				<%
					for (Person person : personList) {
				%>
				<tr class="text-light bg-info">
					<td><%=person.getPersonId()%></td>
					<td><%=person.getPersonName()%></td>
					<td><%=person.getDepartmentId()%></td>
					<td><%=person.getDate()%></td>
					<td><%=person.getRemark()%></td>
					<td><a href="delete_person.htm?personId=<%=person.getPersonId()%>">Delete</a></td>
					<td><a href="select_person.htm?personId=<%=person.getPersonId()%>">Select</a></td>
				</tr>
				<%
					}
				%>
			</tbody>
		</table>
	</div>
</body>
</html>