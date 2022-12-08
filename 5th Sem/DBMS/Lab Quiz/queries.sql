--Retrieve the names of all the courses taught by the Professors during the period 2001- 2004
select names from (select distinct Instructor as names from SECTION where Year between 2001 and 2004) as temp;

-- We need to maintain a report of students as follows:

-- Student_Report(StudentNumber, SectionIdentifier,marks)

-- Populate the report with each student's number, the courses(sectons) he/she has registered/enrolled for, with marks of each student for the courses they have enrolled. 
-- (Marks should be in multiples of 10 with maximum of 100 marks). 