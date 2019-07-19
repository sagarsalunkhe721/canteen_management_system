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

import com.canteenDB.cms.dto.Guest;
import com.canteenDB.cms.dto.Item;

@Repository
public class GuestDaoImple implements GuestDao{

	@Autowired
	private HibernateTemplate hibernateTemplate;
	public void save(Guest guest) {
		hibernateTemplate.execute(new HibernateCallback<List<Guest>>() {

			@Override
			public List<Guest> doInHibernate(Session session) throws HibernateException {
				Transaction t = session.beginTransaction();
				session.save(guest);
				t.commit();
				session.flush();
				session.close();
				return null;
			}
			
		});
		
	}

	@Autowired
	public void update(Guest guest) {
		hibernateTemplate.execute(new HibernateCallback<List<Guest>>() {

			@Override
			public List<Guest> doInHibernate(Session session) throws HibernateException {
				Transaction t = session.beginTransaction();
				session.update(guest);
				t.commit();
				session.flush();
				session.close();
				return null;
			}
			
		});
		
	}

	@Autowired
	public void deleteById(String guestId) {
		hibernateTemplate.execute(new HibernateCallback<List<Guest>>() {

			@Override
			public List<Guest> doInHibernate(Session session) throws HibernateException {
			Transaction t=session.beginTransaction();
			session.delete(guestId);
			t.commit();
			session.flush();
			session.close();
				return null;
			}
		});
	}
	

	@Autowired
	public List<Guest> getAll() {
		List<Guest> gs=hibernateTemplate.execute(new HibernateCallback<List<Guest>>() {
			public List<Guest> doInHibernate(Session session) throws HibernateException {
				Transaction t=session.beginTransaction();
				Query q=session.createQuery("From Guest");
				List<Guest> guestList=q.list();
				t.commit();
				session.flush();
				session.close();
				return guestList;
				
			}
			
			
		});
	
		return gs;
	}

}
