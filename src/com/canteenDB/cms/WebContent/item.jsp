<%@page import="com.canteenDB.cms.dto.Item"%>
<%@page import="java.util.List"%>
<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
 <%
 	List<Item> itemList = (List<Item>)request.getAttribute("ul");
 %>   
<!DOCTYPE html>
<html>
<head>
<meta charset="ISO-8859-1">
<title>Insert title here</title>
</head>
<body>
	
	<a href="prep_item_form.htm">Add Item</a>
	
	<table>
		<%
			for(Item item : itemList){
		%>
			<tr>
				<td><%=item.getItemId() %></td>
				<td><%=item.getItemName() %></td>
				<td><%=item.getCourseId() %></td>
				<td><%=item.getItemType() %></td>
				<td><%=item.getItemPrice() %></td>
				<td><a href="delete_item.htm?itemId=<%=item.getItemId() %>" >Delete</a></td>
				<td><a href="select_item.htm?itemId=<%=item.getItemId() %>" >Select</a></td>
			</tr>
			<h2><%=item.getItemId() %></h2>
		<% }  %>
	</table>
</body>
</html>