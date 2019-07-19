package com.canteenDB.cms.dto;

import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.Id;
import javax.persistence.Table;

@Entity
@Table(name = "items")
public class Item {
	@Column(name = "item_name")
	private String itemName;
	@Id
	@Column(name = "item_id")
//	@GeneratedValue
	private String itemId;
	@Column(name = "course_id")
	private String courseId;
	@Column(name = "item_type")
	private String itemType;
	@Column(name = "item_price")
	private Double itemPrice;
	public Item() {
		super();
		// TODO Auto-generated constructor stub
	}
	
	public Item(String itemId) {
		super();
		this.itemId = itemId;
	}

	public Item(String itemName, String courseId, String itemType, Double itemPrice) {
		super();
		this.itemName = itemName;
		this.courseId = courseId;
		this.itemType = itemType;
		this.itemPrice = itemPrice;
	}

	public Item(String itemName, String itemId, String courseId, String itemType, Double itemPrice) {
		super();
		this.itemName = itemName;
		this.itemId = itemId;
		this.courseId = courseId;
		this.itemType = itemType;
		this.itemPrice = itemPrice;
	}
	

	public String getItemName() {
		return itemName;
	}

	public void setItemName(String itemName) {
		this.itemName = itemName;
	}

	public String getItemId() {
		return itemId;
	}

	public void setItemId(String itemId) {
		this.itemId = itemId;
	}

	public String getCourseId() {
		return courseId;
	}

	public void setCourseId(String courseId) {
		this.courseId = courseId;
	}

	public String getItemType() {
		return itemType;
	}

	public void setItemType(String itemType) {
		this.itemType = itemType;
	}

	public Double getItemPrice() {
		return itemPrice;
	}

	public void setItemPrice(Double itemPrice) {
		this.itemPrice = itemPrice;
	}

	@Override
	public String toString() {
		return itemId + " " + itemName + " " + courseId + " " + itemType + " " + itemPrice;
	}
	
	
}