/*
 * CS106L Assignment 1: SimpleEnroll
 * Created by Fabio Ibanez with modifications by Jacob Roberts-Baca.
 *
 * Welcome to Assignment 1 of CS106L! Please complete each STUDENT TODO
 * in this file. You do not need to modify any other files.
 *
 * Students must implement: parse_csv, write_courses_offered,
 * write_courses_not_offered
 */

#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

const std::string COURSES_OFFERED_PATH = "student_output/courses_offered.csv";
const std::string COURSES_NOT_OFFERED_PATH = "student_output/courses_not_offered.csv";

/**
 * Represents a course a student can take in ExploreCourses.
 * You must fill in the types of the fields in this struct.
 * Hint: Remember what types C++ streams work with?!
 */
struct Course {
  /* STUDENT TODO */std::string title;
  /* STUDENT TODO */std::string number_of_units;
  /* STUDENT TODO */std::string quarter;
};

/**
 * (STUDENT TODO) Look at how the main function (at the bottom of this file)
 * calls `parse_csv`, `write_courses_offered`, and `write_courses_not_offered`.
 * Modify the signatures of these functions so that they work as intended, and then delete this
 * comment!
 */

/**
 * Note:
 * We need to #include utils.cpp _after_ we declare the Course struct above
 * so that the code inside utils.cpp knows what a Course is.
 * Recall that #include literally copies and pastes file contents.
 */
#include "utils.cpp"

/**
 * This function should populate the `courses` vector with structs of type
 * `Course`. We want to create these structs with the records in the courses.csv
 * file, where each line is a record!
 *
 * Hints:
 * 1) Take a look at the split function we provide in utils.cpp 看一下split函数
 * 2) Each LINE is a record! *this is important, so we're saying it again :>)* 每一行就是一个记录
 * 3) The first line in the CSV defines the column names, so you can ignore it! 忽略首行
 *
 * @param filename The name of the file to parse.
 * @param courses  A vector of courses to populate.
 */
void parse_csv(std::string filename, std::vector<Course>& courses) {
  /* (STUDENT TODO) Your code goes here... */
  std::ifstream input(filename);
  if (!input.is_open()) {
    std::cerr << "无法打开文件" << '\n';
    return;
  }
  std::vector<std::string> split_line;
  std::string line;
  std::getline(input, line);
  while (std::getline(input, line)) {
    split_line = split(line, ',');
    Course course(split_line.at(0), split_line.at(1), split_line.at(2));
    courses.push_back(course);
  }
}

/**
 * This function has TWO requirements.
 *
 * 1) Write the courses that are offered to the file
 * "student_output/courses_offered.csv"
 *
 * 2) Delete the courses that are offered from the `all_courses` vector.
 * IMPORTANT: do this after you write out to the file!
 *
 * HINTS:
 * 1) Keep track of the classes that you need to delete! 记录需要删除的
 * 2) Use the delete_elem_from_vector function we give you! 用这个函数
 * 3) Remember to write the CSV column headers at the beginning of the output! 继续写头
 *    See courses.csv for reference.
 *
 * @param all_courses A vector of all courses gotten by calling `parse_csv`.
 *                    This vector will be modified by removing all offered courses.
 */
void write_courses_offered(std::vector<Course>& all_courses) {
  /* (STUDENT TODO) Your code goes here... */
  std::vector<Course> delete_courses;
  std::ofstream output(COURSES_OFFERED_PATH);
  if (!output.is_open()) {
    std::cerr << "打开文件失败" << '\n';
    return;
  }
  output << "Title,Number of Units,Quarter" << '\n';
  for (auto &all_course : all_courses) {
    if (all_course.quarter != "null") {
      delete_courses.push_back(all_course);
      output << all_course.title << ',' << all_course.number_of_units << ',' << all_course.quarter << '\n';
    }
  }

  for (auto &delete_course : delete_courses) {
    delete_elem_from_vector(all_courses, delete_course);
  }
}

/**
 * This function writes the courses NOT offered to the file
 * "student_output/courses_not_offered.csv".
 *
 * This function is ALWAYS called after the `write_courses_offered` function.
 * `unlisted_courses` will trivially contain classes that are not offered
 * since you delete offered classes from `all_courses` in the
 * `write_courses_offered` function.
 *
 * HINT: This should be VERY similar to `write_courses_offered`
 *
 * @param unlisted_courses A vector of courses that are not offered.
 */
void write_courses_not_offered(const std::vector<Course>& unlisted_courses) {
  /* (STUDENT TODO) Your code goes here... */
  std::ofstream output(COURSES_NOT_OFFERED_PATH);
  if(!output.is_open()) {
    std::cerr << "文件无法打开" << '\n';
    return;
  }
  output << "Title,Number of Units,Quarter" << '\n';
  for (auto &unlisted_course : unlisted_courses) {
      output << unlisted_course.title << ',' << unlisted_course.number_of_units << ',' << unlisted_course.quarter << '\n';
  }
}

int main() {
  /* Makes sure you defined your Course struct correctly! */
  static_assert(is_valid_course<Course>, "Course struct is not correctly defined!");

  std::vector<Course> courses;
  parse_csv("courses.csv", courses);

  /* Uncomment for debugging... */
  // print_courses(courses);

  write_courses_offered(courses);
  write_courses_not_offered(courses);

  return run_autograder();
}