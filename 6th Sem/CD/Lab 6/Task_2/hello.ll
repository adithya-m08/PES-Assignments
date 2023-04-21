@.str = constant [13 x i8] c"Hello world\0A\00"

@.myname = constant [26 x i8] c"My name is Sathyajeeth R\0A\00"

define dso_local i32 @main(){
  %printstr = getelementptr [13 x i8], [13 x i8]* @.str, i64 0, i64 0
  %my_name_pointer = getelementptr [26 x i8], [26 x i8]* @.myname, i64 0, i64 0
  %1 = call i32 (i8*, ...)@printf(i8* %printstr)
  %2 = call i32 (i8*, ...)@printf(i8* %my_name_pointer)
  ret i32 0
}

declare i32 @printf(i8*, ...)