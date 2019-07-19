<%@page import="com.canteenDB.cms.dto.Item"%>
<%@page import="java.util.List"%>
<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
	pageEncoding="ISO-8859-1"%>

<%-- <%@ taglib uri="http://www.springframework.org/tags/form" prefix="spr"%> --%>
<%
	List<Item> itemList = (List<Item>) request.getAttribute("ul");
%>
<!DOCTYPE html>
<html>
<head>
<meta charset="ISO-8859-1">
<title>Items</title>
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
				<a class="navbar-brand" href="#">CDAC CANTEEN</a>
				<div class="collapse navbar-collapse" id="navbarNavAltMarkup">
					<div class="navbar-nav">
						<a class="nav-item nav-link active" href="item_list.htm">Items
							<span class="sr-only">(current)</span>
						</a> <a class="nav-item nav-link" href="#">Course</a> <a
							class="nav-item nav-link" href="#">Departments</a> <a
							class="nav-item nav-link" href="#">Person</a> <a
							class="nav-item nav-link" href="#">Guest</a>
					</div>
				</div>
			</nav>
		</div>
		<div class="row d-flex make-center bg-secondary "
			style="height: 55px;">
			<div class="ml-3">
				<a class="btn btn-primary" href="prep_item_form.htm">Add Item</a>
			</div>
			<div class="ml-3">
				<input type="text" class="form-control rounded"
					placeholder="Search Item" />
			</div>
			<div class="ml-3">
				<input class="btn btn-success form-control rounded" type="submit"
					value="Search" />
			</div>
		</div>
		<table class="table table-striped table-bordered">
			<thead class="thead-dark">
				<tr>
					<th scope="col">Item Id</th>
					<th scope="col">Name</th>
					<th scope="col">Course Id</th>
					<th scope="col">Item Type</th>
					<th scope="col">Item Price</th>
					<th scope="col">Delete</th>
					<th scope="col">Edit</th>
				</tr>
			</thead>
			<tbody>

				<%
					for (Item item : itemList) {
				%>
				<tr class="text-light bg-info">
					<td><%=item.getItemId()%></td>
					<td><%=item.getItemName()%></td>
					<td><%=item.getCourseId()%></td>
					<td><%=item.getItemType()%></td>
					<td><%=item.getItemPrice()%></td>
					<td><a href="delete_item.htm?itemId=<%=item.getItemId()%>">Delete</a></td>
					<td><a href="select_item.htm?itemId=<%=item.getItemId()%>">Select</a></td>
				</tr>
				<%
					}
				%>
			</tbody>
		</table>
	</div>
</body>
</html>