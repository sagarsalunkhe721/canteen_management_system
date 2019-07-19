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

import com.canteenDB.cms.dto.Department;
import com.canteenDB.cms.dto.Item;


@Repository
public class DepartmentDaoImple implements DepartmentDao {

	@Autowired
	private HibernateTemplate hibernateTemplate;
	public void save(final Department department) {
		hibernateTemplate.execute(new HibernateCallback<List<Department>>() {
			public List<Department> doInHibernate(Session session) throws HibernateException {
				Transaction t = session.beginTransaction();
				session.save(department);
				t.commit();
				session.flush();
				session.close();
				return null;
			}
		});
	}

	public void deleteById(final String departmentId) {
		hibernateTemplate.execute(new HibernateCallback<List<Department>>() {
			public List<Department> doInHibernate(Session session) throws HibernateException {
				Transaction t = session.beginTransaction();
				session.delete(new Item(departmentId));
				t.commit();
				session.flush();
				session.close();
				return null;
			}
		});
	}
	
	public void update(final Department department) {
		
		hibernateTemplate.execute(new HibernateCallback<List<Department>>() {
			public List<Department> doInHibernate(Session session) throws HibernateException {
				Transaction t = session.beginTransaction();
				session.update(department);
				t.commit();
				session.flush();
				session.close();
				return null;
			}
		});
	}

	public List<Department> getAll() {
		List<Department> ul = hibernateTemplate.execute(new HibernateCallback<List<Department>>() {
			public List<Department> doInHibernate(Session session) throws HibernateException {
				Transaction t = session.beginTransaction();
				Query q = session.createQuery("from Department");
				List<Department> departmentList = q.list();
				t.commit();
				session.flush();
				session.close();
				return departmentList;
			}
		});
		return ul;
	}

	


	
}