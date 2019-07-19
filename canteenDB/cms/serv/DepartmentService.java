package com.canteenDB.cms.serv;

import java.util.List;

import com.canteenDB.cms.dto.Department;
import com.canteenDB.cms.dto.Item;

public interface DepartmentService {	
	public void createDepartment(Department department);
	public void removeDepartment(String departmentId);
	public void modifyDepartment(Department department);
	public List<Department> selectAllDepartment();
}
