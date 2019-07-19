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
<title>Add Department</title>
</head>
<body>
	<div class="container-fluid">
		<div class="row bg-dark">
			<nav class="navbar navbar-expand-lg bg-dark">
				<a class="navbar-brand" href="#">CDAC CANTEEN</a>
				<div class="collapse navbar-collapse" id="navbarNavAltMarkup">
					<div class="navbar-nav">
						<a class="nav-department nav-link active" href="add_department.jsp">Department
							<span class="sr-only">(current)</span>
						</a> <a class="nav-department nav-link" href="#">Course</a> <a
							class="nav-Department nav-link" href="#">Departments</a> <a
							class="nav-Department nav-link" href="#">Person</a> <a
							class="nav-Department nav-link" href="#">Guest</a>
					</div>
				</div>
			</nav>
		</div>
		<div class="row">
			<div class="d-none col-md-3 d-md-block"></div>
			<div class="col-md-6 make-center">
				<div class="bg-info w-50 mt-5 rounded">

					<div class="make-center mt-2 badge">Enter Item Info</div>
					<spr:form action="add_department.htm" commandName="department">
						<div class="make-center mt-2">
							<div>
								<spr:input path="DepartmentName" class="form-control rounded"
									placeholder="Enter Department Name" />
							</div>
						</div>

						<div class="make-center mt-2">
							<div>
								<spr:input path="departmentId" class="form-control rounded"
									placeholder="Enter Department Id" />
							</div>
						</div>
						<div class="make-center mt-2">
							<div>
								<spr:select path="courseId" class="form-control rounded" style="width:200px">
									<spr:option value="Main Course">Main course</spr:option>
									<spr:option value="ABC">ABC</spr:option>
								</spr:select>
							</div>
						</div>
						<div class="make-center mt-2">
							<div>
								<spr:select path="itemType" class="form-control rounded" style="width:200px">
									<spr:option value="Ready to serve">Ready to serve</spr:option>
									<spr:option value="Raw">Raw</spr:option>
								</spr:select>
							</div>
						</div>
						<div class="make-center mt-2">
							<div>
								<spr:input path="itemPrice" class="form-control rounded"
									placeholder="Enter Price"  />
							</div>
						</div>

						<div class="make-center mt-2">
							<input class="btn btn-success rounded" type="submit"
								value="Add Item" style="width:200px"/>
						</div>
					</spr:form>

					<div class="make-center mt-2 mb-2">
						<a class=" btn btn-primary rounded text-light" style="width:200px" href="item_list.htm" >Back</a>
					</div>
				</div>
			</div>
		</div>

	</div>
</body>
</html>