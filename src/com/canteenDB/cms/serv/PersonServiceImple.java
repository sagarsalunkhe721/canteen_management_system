package com.canteenDB.cms.serv;

import java.util.List;

import com.canteenDB.cms.dao.PersonDao;
import com.canteenDB.cms.dto.Person;

public class PersonServiceImple implements PersonService {
	
	private PersonDao personDao;

	@Override
	public void Add(Person person) {
		// TODO Auto-generated method stub
		personDao.Add(person);
		
	}

	@Override
	public void Update(Person person) {
		// TODO Auto-generated method stub
		personDao.Update(person);
		
		
	}

	@Override
	public void DeleteById(String personId) {
		// TODO Auto-generated method stub
		personDao.DeleteById(personId);
	
		
	}

	@Override
	public List<Person> GetAll() {
		// TODO Auto-generated method stub
		return 	personDao.GetAll();
		
	}

	@Override
	public Person GetPersonById(String personId) {
		// TODO Auto-generated method stub
		return personDao.GetPersonById(personId);

	}
	

}
