package com.canteenDB.cms.dto;

import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.Id;
import javax.persistence.Table;

@Entity
@Table(name = "department")
public class Department {
	@Column(name = "department_name")
	private String departmentName;
	@Id
	@Column(name = "department_id")
//	@GeneratedValue
	private String departmentId;
	public Department() {
		super();
		// TODO Auto-generated constructor stub
	}
	
	public Department(String itemId) {
		super();
		this.departmentId = departmentId;
	}

	public Department(String departmentName, String departmentId) {
		super();
		this.departmentName = departmentName;
		this.departmentId = departmentId;
		
	}

	public String getDepartmentName() {
		return departmentName;
	}

	public void setDepartmentName(String departmentName) {
		this.departmentName = departmentName;
	}

	public String getDepartmentId() {
		return departmentId;
	}

	public void setDepartmentId(String departmentId) {
		this.departmentId = departmentId;
	}

	@Override
	public String toString() {
		return "Department [departmentName=" + departmentName + ", departmentId=" + departmentId + "]";
	}



}