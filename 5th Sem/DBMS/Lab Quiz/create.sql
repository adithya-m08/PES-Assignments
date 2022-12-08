CREATE TABLE STUDENT (
    Name varchar(30) not null,
    StudentNumber int not null,
    Class int not null,
    Major varchar(4),
    CONSTRAINT STUDENT_pk PRIMARY KEY(StudentNumber)
);
CREATE TABLE COURSE (
    CourseName varchar(30) not null,
    CourseNumber varchar(8) not null,
    CreditHours int not null,
    Department varchar(4),
    CONSTRAINT COURSE_pk PRIMARY KEY(CourseNumber)
);
CREATE TABLE SECTION (
    SectionIdentifier int not null,
    CourseNumber varchar(8) not null,
    Semester varchar(6) not null,
    Year int not null,
    Instructor varchar(30) not null,
    CONSTRAINT SECTION_pk PRIMARY KEY(SectionIdentifier),
    CONSTRAINT SECTION_cn_fk FOREIGN KEY(CourseNumber) REFERENCES COURSE(CourseNumber) ON DELETE CASCADE ON UPDATE CASCADE
);
CREATE TABLE GRADE_REPORT (
    StudentNumber int not null,
    SectionIdentifier int not null,
    Grade char(1),
    CONSTRAINT GRADE_REPORT_pk PRIMARY KEY(StudentNumber, SectionIdentifier),
    CONSTRAINT GRADE_REPORT_sn_fk FOREIGN KEY(StudentNumber) REFERENCES STUDENT(StudentNumber) ON DELETE CASCADE ON UPDATE CASCADE,
    CONSTRAINT GRADE_REPORT_si_fk FOREIGN KEY(SectionIdentifier) REFERENCES SECTION(SectionIdentifier) ON DELETE CASCADE ON UPDATE CASCADE
);
CREATE TABLE PREREQUISITE (
    CourseNumber varchar(8) not null,
    PrerequisiteNumber varchar(8) not null,
    CONSTRAINT PREREQUISITE_pk PRIMARY KEY(CourseNumber, PrerequisiteNumber),
    CONSTRAINT PREREQUISITE_cn_fk FOREIGN KEY(CourseNumber) REFERENCES COURSE(CourseNumber) ON DELETE CASCADE ON UPDATE CASCADE,
    CONSTRAINT PREREQUISITE_pn_fk FOREIGN KEY(PrerequisiteNumber) REFERENCES COURSE(CourseNumber) ON DELETE CASCADE ON UPDATE CASCADE
);
INSERT into STUDENT
values ('Madhavan', 154, 3, 'CS'),
    ('Ram', 15, 4, 'CS'),
    ('Akash', 17, 4, 'CS'),
    ('Reena', 16, 3, 'EC');
INSERT into COURSE
values ('DSA', '16CS237', 4, 'CS'),
    ('DBMS', '16CS154', 4, 'CS'),
    ('DMS', '16CS243', 3, 'CS'),
    ('OS', '16CS180', 3, 'CS');
INSERT into SECTION
values (1, '16CS243', '3', 2001, 'Prof1'),
    (2, '16CS237', '3', 2003, 'Prof2'),
    (3, '16CS154', '5', 2005, 'Prof3'),
    (4, '16CS243', '3', 2006, 'Prof4'),
    (5, '16CS237', '3', 2019, 'Prof2'),
    (6, '16CS180', '3', 2004, 'Prof5');
INSERT into GRADE_REPORT
values (154, 4, 'C'),
    (154, 5, 'B'),
    (15, 1, 'A'),
    (15, 2, 'A'),
    (15, 3, 'A'),
    (15, 6, 'A'),
    (17, 4, 'C'),
    (17, 5, 'B');
INSERT into PREREQUISITE
values ('16CS180', '16CS154'),
    ('16CS180', '16CS243'),
    ('16CS154', '16CS237');

--Retrieve the names of all the courses taught by the Professors during the period 2001- 2004
SELECT DISTINCT COURSE.CourseName
FROM COURSE,
    SECTION
WHERE COURSE.CourseNumber = SECTION.CourseNumber
    AND SECTION.Year BETWEEN 2001 AND 2004;

--Student_Report(StudentNumber, SectionIdentifier,marks) Populate the report with each student's number, the courses(sectons) he/she has registered/enrolled for, with marks of each student for the courses they have enrolled.  (Marks should be in multiples of 10 with maximum of 100 marks).  ****You cannot use insert statement directly for the above question to populate existing data, Only for new data to be inserted you can use insert statement directly****
CREATE TABLE Student_Report (
    StudentNumber int not null,
    SectionIdentifier int not null,
    marks int
);
INSERT into Student_Report(StudentNumber, SectionIdentifier, marks)
SELECT GRADE_REPORT.StudentNumber,
    GRADE_REPORT.SectionIdentifier,
    CASE
        WHEN GRADE_REPORT.Grade = 'A' THEN 100
        WHEN GRADE_REPORT.Grade = 'B' THEN 80
        WHEN GRADE_REPORT.Grade = 'C' THEN 60
        WHEN GRADE_REPORT.Grade = 'D' THEN 40
        WHEN GRADE_REPORT.Grade = 'E' THEN 20
        ELSE 0
    END
FROM GRADE_REPORT;

--Create a trigger so that the total marks scored by each student is automatically updated in the result sheet whenever a record is inserted into Student_Report. students_result(StudentNumber,Totalmarks)
CREATE TABLE student_result (
    StudentNumber int not null,
    Totalmarks int
);

INSERT into student_result(StudentNumber, Totalmarks)
SELECT StudentNumber,
    SUM(marks)
FROM Student_Report
GROUP BY StudentNumber;

DELIMITER $$
CREATE or REPLACE TRIGGER update_total_marks
AFTER INSERT ON Student_Report
FOR EACH ROW
BEGIN
    UPDATE student_result
    SET Totalmarks = Totalmarks + NEW.marks
    WHERE StudentNumber = NEW.StudentNumber;
END;
$$
DELIMITER ;

-- Create a trigger to specify the remarks based on the Major of a student as follows: Major 'CS' ---> "Computer Science Engg" Major 'EC'   ---> "Electronics Engg
ALTER TABLE student_result
ADD Remarks varchar(30);

DELIMITER $$
CREATE function get_remarks(major varchar(4))
RETURNS varchar(30)
BEGIN
    DECLARE remarks varchar(30);
    IF major = 'CS' THEN
        SET remarks = 'Computer Science Engg';
    ELSEIF major = 'EC' THEN
        SET remarks = 'Electronics Engg';
    ELSE
        SET remarks = 'Other';
    END IF;
    RETURN remarks;
END;
$$
DELIMITER ;

DELIMITER $$
CREATE or REPLACE TRIGGER update_remarks
AFTER INSERT ON STUDENT
FOR EACH ROW
BEGIN
    UPDATE student_result
    SET Remarks = get_remarks(NEW.Major)
    WHERE StudentNumber = NEW.StudentNumber;
END;
$$
DELIMITER ;

INSERT INTO STUDENT
VALUES ('Rahul', 18, 4, 'CS');