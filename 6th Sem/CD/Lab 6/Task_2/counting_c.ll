@.targetstr = constant [22 x i8] c"counting c's is cool!\00"
@.formatstr = constant [22 x i8] c"Number of c's is: %d\0A\00"

define dso_local i32 @main(){
    %targetptr = getelementptr [22 x i8], [22 x i8]* @.targetstr, i32 0, i32 0
    %1 = call i32 @countc(i8* %targetptr, i32 22)
    %formatptr = gettelementptr [22 x i8], [22 x i8]* @.formatstr, i64 0 ,i64 0
    %2 = call i32 (i8*, ...) @printf(i8* %formatptr, i32 %1)
    ret i32 0
}

define dso_local i32 @countc(i8* %string, i32 %string_length){
  %c_count = alloca i32
  %index = alloca i32
  store i32 0, i32* %c_count
  store i32 0, i32* %index
  br label %1

1:
  %idx_1 = load i32, i32* %index
  %cmp_l = icmp slt i32 %idx_l, %string_length
  br il %cmp_l, label %2, label %5

2:
    %idx_2 = load i32, i32* %index%charptr = getelementptr i8, i8* %string, i32 %idx_2
    %charpt = 
}

declare i32 @printf(i8*, ...)