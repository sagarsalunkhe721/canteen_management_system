package com.canteenDB.cms.dao;

import java.util.List;

import com.canteenDB.cms.dto.Person;

public interface PersonDao {
	
	public void Add(Person person);
	public void Update(Person person);
	public void DeleteById(String personId);
	public List<Person> GetAll();
	public Person GetPersonById(String personId);
	
	

}
