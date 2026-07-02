# Write your MySQL query statement below
select max(salary) as secondhighestSalary
from Employee
where  salary<(select max(salary) from Employee);