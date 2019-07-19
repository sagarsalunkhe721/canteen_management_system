package com.canteenDB.cms.dto;

import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.Id;
import javax.persistence.Table;

@Entity
@Table(name="guest")
public class Guest {
	@Id
	@Column(name="guest_id")
	private String guestId;
	@Column(name="guest_name")
	private String guestName;
	@Column(name="department_id")
	private String departmentId;
	public Guest() {
		super();
		// TODO Auto-generated constructor stub
	}
	
	public Guest(String guestId) {
		super();
		this.guestId = guestId;
	}

	public Guest(String guestId, String guestName, String departmentId) {
		super();
		this.guestId = guestId;
		this.guestName = guestName;
		this.departmentId = departmentId;
	}

	public String getGuestId() {
		return guestId;
	}

	public void setGuestId(String guestId) {
		this.guestId = guestId;
	}

	public String getGuestName() {
		return guestName;
	}

	public void setGuestName(String guestName) {
		this.guestName = guestName;
	}

	public String getDepartmentId() {
		return departmentId;
	}

	public void setDepartmentId(String departmentId) {
		this.departmentId = departmentId;
	}
	
	
}
