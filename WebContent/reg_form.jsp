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
<title>Register</title>
</head>
<body>

	<div class="container-fluid">
		<div class="row bg-dark"
			style="height: 55px; position: sticky; top: 0; z-index: 9999;">
			<div class="col-3 text-light make-left beautify">CDAC Canteen</div>
		</div>
		<div class="row">
			<div class="d-none col-md-3 d-md-block"></div>
			<div class="col-md-6 make-center">
				<div class="bg-info w-50 mt-5 rounded">

					<div class="make-center mt-2 badge">Enter User Info</div>
					<spr:form action="reg.htm" commandName="user">
						<div class="make-center mt-2">
							<!-- <div class="badge bdg-primary">User Name :</div>  -->
							<div>
								<spr:input path="userName" class="form-control rounded"
									placeholder="Enter Username" />
							</div>
						</div>

						<div class="make-center mt-2">
							<!-- <div class="badge badge-primary">Password :</div>  -->
							<div>
								<spr:input path="userPass" type="password" class="form-control rounded"
									placeholder="Enter Password" />
							</div>
						</div>

						<div class="make-center mt-2">
							<div style="width:200px">
								<spr:select path="userRole" class="form-control rounded">
									<spr:option value="admin">Admin</spr:option>
									<spr:option value="operator">Supervisor</spr:option>
								</spr:select>
							</div>

						</div>

						<div class="make-center mt-2">
							<input class="btn btn-success rounded" style="width:200px" type="submit"
								value="Register" />
						</div>
					</spr:form>

					<div class="make-center mt-2 mb-2">
							<a class="text-light btn btn-primary rounded" style="width:200px" href="prep_login_form.htm">Login</a>
					</div>
				</div>
			</div>
		</div>
	</div>
</body>
</html>