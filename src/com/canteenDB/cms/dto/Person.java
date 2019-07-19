package com.canteenDB.cms.dto;

import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.Id;
import javax.persistence.Table;


@Entity
@Table(name="person")
public class Person {
	@Column(name = "person_name")
	private String personName;
	@Id
	@Column(name="person_Id")
	private String personId;
	
	
	@Column(name="dept_Id")
	private String deptId;
	
	@Column(name="settlement_type")
	private String settlementType;
	
	@Column(name="date")
	private String date;
	
	@Column(name="remark")
	private String remark;

	public Person() {
		super();
		// TODO Auto-generated constructor stub
	}

	
	
	public String getPersonName() {
		return personName;
	}



	public void setPersonName(String personName) {
		this.personName = personName;
	}



	public String getPersonId() {
		return personId;
	}



	public void setPersonId(String personId) {
		this.personId = personId;
	}



	public String getDeptId() {
		return deptId;
	}



	public void setDeptId(String deptId) {
		this.deptId = deptId;
	}



	public String getSettlementType() {
		return settlementType;
	}



	public void setSettlementType(String settlementType) {
		this.settlementType = settlementType;
	}



	public String getDate() {
		return date;
	}



	public void setDate(String date) {
		this.date = date;
	}



	public String getRemark() {
		return remark;
	}



	public void setRemark(String remark) {
		this.remark = remark;
	}



	public Person(String deptId) {
		super();
		this.deptId = deptId;
	}

	public Person(String personName, String personId, String settlementType, String date, String remark) {
		super();
		this.personName = personName;
		this.personId = personId;
		this.settlementType = settlementType;
		this.date = date;
		this.remark = remark;
	}

	public Person(String personName, String personId, String deptId, String settlementType, String date,
			String remark) {
		super();
		this.personName = personName;
		this.personId = personId;
		this.deptId = deptId;
		this.settlementType = settlementType;
		this.date = date;
		this.remark = remark;
	}

	@Override
	public String toString() {
		return "Person [personName=" + personName + ", personId=" + personId + ", deptId=" + deptId
				+ ", settlementType=" + settlementType + ", date=" + date + ", remark=" + remark + "]";
	}
	
	
  
}
