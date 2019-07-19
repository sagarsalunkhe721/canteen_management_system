package com.canteenDB.cms.dao;
import com.canteenDB.cms.dto.Department;
import com.canteenDB.cms.dto.Item;
import java.util.List;

public interface DepartmentDao {	
	public void save(Department department);	
	public void deleteById(String departmentId);	
	public void update(Department department) ;
	public List<Department> getAll() ;
//	public Item getElementById(String itemId);
}