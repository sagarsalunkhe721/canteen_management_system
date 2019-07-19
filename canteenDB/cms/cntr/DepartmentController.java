package com.canteenDB.cms.cntr;

import java.util.List;

//import javax.servlet.http.HttpSession;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.ModelMap;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;

import com.canteenDB.cms.dto.Department;
import com.canteenDB.cms.dto.Item;
import com.canteenDB.cms.serv.DepartmentService;
import com.canteenDB.cms.serv.ItemService;

@Controller
public class DepartmentController {
	
	@Autowired
	private DepartmentService departmentService;
	
	
	@RequestMapping(value = "/prep_department_form.htm")
	public String departmentRegForm(ModelMap model) {
		model.put("department", new Department());
		return "add_item";
	}
	
	@RequestMapping(value = "/add_department.htm")
	public String addDepartment(Department department,ModelMap model) {
		departmentService.createDepartment(department);
		model.put("department", new Department());
		List<Department> ulist = departmentService.selectAllDepartment();
		model.put("ul", ulist);
		return "department";
	}
	
	@RequestMapping(value = "/department_list.htm")
	public String departmentList(ModelMap model) {
		List<Department> ulist = departmentService.selectAllDepartment();
		model.put("ul", ulist);
		return "department";
	}
	
	@RequestMapping(value = "/delete_department.htm")
	public String deleteDepartment(@RequestParam String departmentId,ModelMap model) {
		departmentService.removeDepartment(departmentId);
		List<Department> ulist = departmentService.selectAllDepartment();
		model.put("ul", ulist);
		return "department";
	}
	
	@RequestMapping(value= "/select_department.htm")
	public String updateDepartment(@RequestParam Department department, ModelMap model) {
		departmentService.modifyDepartment(department);
		model.put("department", new Department());
		return "add_department";
	}
	
}