select d.name as department,e.name as employee,e.salary
from employee e
join department d
on e.departmentId=d.id
where (e.departmentId,salary) in 
(select departmentId,max(salary)
from employee
group by departmentId);