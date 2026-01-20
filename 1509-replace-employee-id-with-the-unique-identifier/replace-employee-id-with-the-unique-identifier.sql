# Write your MySQL query statement below
select empUni.unique_id , emp.name from Employees emp left join EmployeeUNI empUni on empUni.id=emp.id