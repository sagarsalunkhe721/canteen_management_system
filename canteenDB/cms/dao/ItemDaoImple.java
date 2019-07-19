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

import com.canteenDB.cms.dto.Item;


@Repository
public class ItemDaoImple implements ItemDao {

	@Autowired
	private HibernateTemplate hibernateTemplate;
	public void save(final Item item) {
		hibernateTemplate.execute(new HibernateCallback<List<Item>>() {
			public List<Item> doInHibernate(Session session) throws HibernateException {
				Transaction t = session.beginTransaction();
				session.save(item);
				t.commit();
				session.flush();
				session.close();
				return null;
			}
		});
	}

	public void deleteById(final String itemId) {
		hibernateTemplate.execute(new HibernateCallback<List<Item>>() {
			public List<Item> doInHibernate(Session session) throws HibernateException {
				Transaction t = session.beginTransaction();
				session.delete(new Item(itemId));
				t.commit();
				session.flush();
				session.close();
				return null;
			}
		});
	}
	
	/*@Override
	public Item getElementById(String itemId) {
		hibernateTemplate.execute(new HibernateCallback<List<Item>>() {
			public List<Item> doInHibernate(Session session) throws HibernateException {
				Transaction t = session.beginTransaction();
				Query q = session.createQuery("from Item where itemId= itemId");
				
			}
	}
*/

	public void update(final Item item) {
		
		hibernateTemplate.execute(new HibernateCallback<List<Item>>() {
			public List<Item> doInHibernate(Session session) throws HibernateException {
				Transaction t = session.beginTransaction();
				session.update(item);
				t.commit();
				session.flush();
				session.close();
				return null;
			}
		});
	}

	public List<Item> getAll() {
		List<Item> ul = hibernateTemplate.execute(new HibernateCallback<List<Item>>() {
			public List<Item> doInHibernate(Session session) throws HibernateException {
				Transaction t = session.beginTransaction();
				Query q = session.createQuery("from Item");
				List<Item> itemList = q.list();
				t.commit();
				session.flush();
				session.close();
				return itemList;
			}
		});
		return ul;
	}

	

	
}