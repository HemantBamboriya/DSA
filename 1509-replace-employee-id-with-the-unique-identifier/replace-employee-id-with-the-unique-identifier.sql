# Write your MySQL query statement below
select e.name, u.unique_id
from Employees as e
left join EmployeeUNI as u
On e.id=u.id;
