<%@page import="com.canteenDB.cms.dto.Person"%>
<%@page import="java.util.List"%>
<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
 <%
 	List<Person> personList = (List<Person>)request.getAttribute("ul");
 %>   
<!DOCTYPE html>
<html>
<head>
<meta charset="ISO-8859-1">
<title>Insert title here</title>
</head>
<body>
	
	<a href="prep_person_form.htm">Add Person</a>
	
	<table>
		<%
			for(Person person : personList){
		%>
			<tr>
				<td><%=person.getPersonId() %></td>
				<td><%=person.getPersonName() %></td>
				<td><%=person.getDeptId() %></td>
				<td><%=person.getSettlementType() %></td>
				<td><%=person.getDate() %></td>
				<td><a href="delete_person.htm?personId=<%=person.getPersonId() %>" >Delete</a></td>
				<td><a href="select_person.htm?personId=<%=person.getPersonId() %>" >Select</a></td>
			</tr>
			<h2><%=person.getPersonId() %></h2>
		<% }  %>
	</table>
</body>
</html>