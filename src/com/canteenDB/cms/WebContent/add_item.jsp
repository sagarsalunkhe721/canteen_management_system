<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
	pageEncoding="ISO-8859-1"%>

<%@ taglib uri="http://www.springframework.org/tags/form" prefix="spr"%>

<!DOCTYPE html>
<html>
<head>
<link rel="stylesheet"
	href="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/css/bootstrap.min.css">
<script
	src="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/js/bootstrap.min.js"></script>
<link rel="stylesheet" href="css/style.css">
<meta charset="ISO-8859-1">
<title>Add Items</title>
</head>
<body>
	<div class="container-fluid">
		<div class="row bg-dark">
			<nav class="navbar navbar-expand-lg bg-dark">
				<a class="navbar-brand" href="#">CDAC CANTEEN</a>
				<div class="collapse navbar-collapse" id="navbarNavAltMarkup">
					<div class="navbar-nav">
						<a class="nav-item nav-link active" href="add_item.jsp">Items
							<span class="sr-only">(current)</span>
						</a> <a class="nav-item nav-link" href="#">Course</a> <a
							class="nav-item nav-link" href="#">Departments</a> <a
							class="nav-item nav-link" href="#">Person</a> <a
							class="nav-item nav-link" href="#">Guest</a>
					</div>
				</div>
			</nav>
		</div>
		<div class="row">
			<div class="d-none col-md-3 d-md-block"></div>
			<div class="col-md-6 make-center">
				<div class="bg-info w-50 mt-5 rounded">

					<div class="make-center mt-2 badge">Enter Item Info</div>
					<spr:form action="add_item.htm" commandName="item">
						<div class="make-center mt-2">
							<div>
								<spr:input path="itemName" class="form-control rounded"
									placeholder="Enter Item Name" />
							</div>
						</div>

						<div class="make-center mt-2">
							<div>
								<spr:input path="itemId" class="form-control rounded"
									placeholder="Enter Item Id" />
							</div>
						</div>
						<div class="make-center mt-2">
							<div>
								<spr:select path="courseId" class="form-control rounded">
									<spr:option value="admin">Main course</spr:option>
									<spr:option value="operator">A</spr:option>
								</spr:select>
							</div>
						</div>
						<div class="make-center mt-2">
							<div>
								<spr:select path="itemType" class="form-control rounded">
									<spr:option value="admin">Ready to serve</spr:option>
									<spr:option value="operator">Raw</spr:option>
								</spr:select>
							</div>
						</div>
						<div class="make-center mt-2">
							<div>
								<spr:input path="itemPrice" class="form-control rounded"
									placeholder="Enter Price" />
							</div>
						</div>

						<div class="make-center mt-2">
							<input class="btn btn-success w-25 rounded" type="submit"
								value="Add Item" />
						</div>
					</spr:form>

					<div class="make-center mt-2 mb-2">
						<div class="btn btn-primary w-25 rounded">
							<a class="text-light" href="item_list.htm">Back</a>
						</div>
					</div>
				</div>
			</div>
		</div>

	</div>
</body>
</html>