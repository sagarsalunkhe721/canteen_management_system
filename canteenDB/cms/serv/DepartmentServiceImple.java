package com.canteenDB.cms.serv;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import com.canteenDB.cms.dao.DepartmentDao;
import com.canteenDB.cms.dao.ItemDao;
import com.canteenDB.cms.dto.Department;
import com.canteenDB.cms.dto.Item;


@Service
public class DepartmentServiceImple implements DepartmentService {
	@Autowired
	private DepartmentDao departmentDao;
	
	
	public void createDepartment(Department department) {
		departmentDao.save(department);
	}
	
	public void removeDepartment(String departmentId) {
		departmentDao.deleteById(departmentId);
	}
	
	public void modifyDepartment(Department department) {
		departmentDao.update(department);
	}
	
	public List<Department> selectAllDepartment() {
		return departmentDao.getAll();
	}
	
}