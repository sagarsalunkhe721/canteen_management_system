package com.canteenDB.cms.dao;

import java.util.List;

import org.hibernate.HibernateException;
import org.hibernate.Query;
import org.hibernate.Session;
import org.hibernate.Transaction;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.orm.hibernate4.HibernateCallback;
import org.springframework.orm.hibernate4.HibernateTemplate;
import org.springframework.stereotype.Repository;


import com.canteenDB.cms.dto.Person;


@Repository
public class PersonDaoImple implements PersonDao {

	@Autowired
	private HibernateTemplate hibernateTemplate;
	public void save(final Person person) {
		hibernateTemplate.execute(new HibernateCallback<List<Person>>() {
			public List<Person> doInHibernate(Session session) throws HibernateException {
				Transaction t = session.beginTransaction();
				session.save(person);
				t.commit();
				session.flush();
				session.close();
				return null;
			}
		});
	}

	public void deleteById(final String personId) {
		hibernateTemplate.execute(new HibernateCallback<List<Person>>() {
			public List<Person> doInHibernate(Session session) throws HibernateException {
				Transaction t = session.beginTransaction();
				session.delete(new Person(personId));
				t.commit();
				session.flush();
				session.close();
				return null;
			}
		});
	}

	public void update(final Person person) {
		
		hibernateTemplate.execute(new HibernateCallback<List<Person>>() {
			public List<Person> doInHibernate(Session session) throws HibernateException {
				Transaction t = session.beginTransaction();
				session.update(person);
				t.commit();
				session.flush();
				session.close();
				return null;
			}
		});
	}

	public List<Person> getAll() {
		List<Person> ul = hibernateTemplate.execute(new HibernateCallback<List<Person>>() {
			public List<Person> doInHibernate(Session session) throws HibernateException {
				Transaction t = session.beginTransaction();
				Query q = session.createQuery("from Item");
				List<Person> personList = q.list();
				t.commit();
				session.flush();
				session.close();
				return personList;
			}
		});
		return ul;
	}

	@Override
	public void Add(Person person) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void Update(Person person) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void DeleteById(String personId) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public List<Person> GetAll() {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public Person GetPersonById(String personId) {
		// TODO Auto-generated method stub
		return null;
	}

	
}