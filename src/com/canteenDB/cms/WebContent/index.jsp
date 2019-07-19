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
<title>Login</title>
</head>
<body class="bg-seconary">
	<div class="container-fluid">
		<div class="row bg-dark"
			style="height: 55px; position: sticky; top: 0; z-index: 9999;">
			<div class="col-3 text-light make-left beautify">CDAC Canteen</div>
		</div>
		<div class="row">
			<div class="d-none col-md-3 d-md-block"></div>
			<div class="col-md-6 make-center">
				<div class="bg-info w-50 mt-5 rounded">

					<div class="make-center mt-2 badge">Login</div>
					<spr:form action="login.htm" commandName="user">
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
								<spr:input path="userPass" class="form-control rounded"
									placeholder="Enter Username" />
							</div>
						</div>
						<div class="make-center mt-2">
							<input class="btn btn-success w-25 rounded" type="submit"
								value="Login" />
						</div>
					</spr:form>

					<div class="make-center mt-2 mb-2">
						<div class="btn btn-primary w-25 rounded">
							<a class="text-light" href="prep_reg_form.htm">Register</a>
						</div>
					</div>
				</div>
			</div>
		</div>
	</div>
</body>
</html>