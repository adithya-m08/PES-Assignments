; ModuleID = 'word.c'
source_filename = "word.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

@__const.main.str = private unnamed_addr constant [38 x i8] c"A jellyfish stringed me on the bench.\00", align 16
@__const.main.c = private unnamed_addr constant [9 x i8] c"stringed\00", align 1
@__const.main.d = private unnamed_addr constant [6 x i8] c"stung\00", align 1
@.str = private unnamed_addr constant [16 x i8] c"Old string: %s\0A\00", align 1
@.str.1 = private unnamed_addr constant [16 x i8] c"New String: %s\0A\00", align 1

; Function Attrs: noinline nounwind uwtable
define dso_local i8* @replaceWord(i8* noundef %s, i8* noundef %oldW, i8* noundef %newW) #0 {
entry:
  %s.addr = alloca i8*, align 8
  %oldW.addr = alloca i8*, align 8
  %newW.addr = alloca i8*, align 8
  %result = alloca i8*, align 8
  %i = alloca i32, align 4
  %cnt = alloca i32, align 4
  %newWlen = alloca i32, align 4
  %oldWlen = alloca i32, align 4
  store i8* %s, i8** %s.addr, align 8
  store i8* %oldW, i8** %oldW.addr, align 8
  store i8* %newW, i8** %newW.addr, align 8
  store i32 0, i32* %cnt, align 4
  %0 = load i8*, i8** %newW.addr, align 8
  %call = call i64 @strlen(i8* noundef %0) #5
  %conv = trunc i64 %call to i32
  store i32 %conv, i32* %newWlen, align 4
  %1 = load i8*, i8** %oldW.addr, align 8
  %call1 = call i64 @strlen(i8* noundef %1) #5
  %conv2 = trunc i64 %call1 to i32
  store i32 %conv2, i32* %oldWlen, align 4
  store i32 0, i32* %i, align 4
  br label %for.cond

for.cond:                                         ; preds = %for.inc, %entry
  %2 = load i8*, i8** %s.addr, align 8
  %3 = load i32, i32* %i, align 4
  %idxprom = sext i32 %3 to i64
  %arrayidx = getelementptr inbounds i8, i8* %2, i64 %idxprom
  %4 = load i8, i8* %arrayidx, align 1
  %conv3 = sext i8 %4 to i32
  %cmp = icmp ne i32 %conv3, 0
  br i1 %cmp, label %for.body, label %for.end

for.body:                                         ; preds = %for.cond
  %5 = load i8*, i8** %s.addr, align 8
  %6 = load i32, i32* %i, align 4
  %idxprom5 = sext i32 %6 to i64
  %arrayidx6 = getelementptr inbounds i8, i8* %5, i64 %idxprom5
  %7 = load i8*, i8** %oldW.addr, align 8
  %call7 = call i8* @strstr(i8* noundef %arrayidx6, i8* noundef %7) #5
  %8 = load i8*, i8** %s.addr, align 8
  %9 = load i32, i32* %i, align 4
  %idxprom8 = sext i32 %9 to i64
  %arrayidx9 = getelementptr inbounds i8, i8* %8, i64 %idxprom8
  %cmp10 = icmp eq i8* %call7, %arrayidx9
  br i1 %cmp10, label %if.then, label %if.end

if.then:                                          ; preds = %for.body
  %10 = load i32, i32* %cnt, align 4
  %inc = add nsw i32 %10, 1
  store i32 %inc, i32* %cnt, align 4
  %11 = load i32, i32* %oldWlen, align 4
  %sub = sub nsw i32 %11, 1
  %12 = load i32, i32* %i, align 4
  %add = add nsw i32 %12, %sub
  store i32 %add, i32* %i, align 4
  br label %if.end

if.end:                                           ; preds = %if.then, %for.body
  br label %for.inc

for.inc:                                          ; preds = %if.end
  %13 = load i32, i32* %i, align 4
  %inc12 = add nsw i32 %13, 1
  store i32 %inc12, i32* %i, align 4
  br label %for.cond, !llvm.loop !6

for.end:                                          ; preds = %for.cond
  %14 = load i32, i32* %i, align 4
  %15 = load i32, i32* %cnt, align 4
  %16 = load i32, i32* %newWlen, align 4
  %17 = load i32, i32* %oldWlen, align 4
  %sub13 = sub nsw i32 %16, %17
  %mul = mul nsw i32 %15, %sub13
  %add14 = add nsw i32 %14, %mul
  %add15 = add nsw i32 %add14, 1
  %conv16 = sext i32 %add15 to i64
  %call17 = call noalias i8* @malloc(i64 noundef %conv16) #6
  store i8* %call17, i8** %result, align 8
  store i32 0, i32* %i, align 4
  br label %while.cond

while.cond:                                       ; preds = %if.end29, %for.end
  %18 = load i8*, i8** %s.addr, align 8
  %19 = load i8, i8* %18, align 1
  %tobool = icmp ne i8 %19, 0
  br i1 %tobool, label %while.body, label %while.end

while.body:                                       ; preds = %while.cond
  %20 = load i8*, i8** %s.addr, align 8
  %21 = load i8*, i8** %oldW.addr, align 8
  %call18 = call i8* @strstr(i8* noundef %20, i8* noundef %21) #5
  %22 = load i8*, i8** %s.addr, align 8
  %cmp19 = icmp eq i8* %call18, %22
  br i1 %cmp19, label %if.then21, label %if.else

if.then21:                                        ; preds = %while.body
  %23 = load i8*, i8** %result, align 8
  %24 = load i32, i32* %i, align 4
  %idxprom22 = sext i32 %24 to i64
  %arrayidx23 = getelementptr inbounds i8, i8* %23, i64 %idxprom22
  %25 = load i8*, i8** %newW.addr, align 8
  %call24 = call i8* @strcpy(i8* noundef %arrayidx23, i8* noundef %25) #6
  %26 = load i32, i32* %newWlen, align 4
  %27 = load i32, i32* %i, align 4
  %add25 = add nsw i32 %27, %26
  store i32 %add25, i32* %i, align 4
  %28 = load i32, i32* %oldWlen, align 4
  %29 = load i8*, i8** %s.addr, align 8
  %idx.ext = sext i32 %28 to i64
  %add.ptr = getelementptr inbounds i8, i8* %29, i64 %idx.ext
  store i8* %add.ptr, i8** %s.addr, align 8
  br label %if.end29

if.else:                                          ; preds = %while.body
  %30 = load i8*, i8** %s.addr, align 8
  %incdec.ptr = getelementptr inbounds i8, i8* %30, i32 1
  store i8* %incdec.ptr, i8** %s.addr, align 8
  %31 = load i8, i8* %30, align 1
  %32 = load i8*, i8** %result, align 8
  %33 = load i32, i32* %i, align 4
  %inc26 = add nsw i32 %33, 1
  store i32 %inc26, i32* %i, align 4
  %idxprom27 = sext i32 %33 to i64
  %arrayidx28 = getelementptr inbounds i8, i8* %32, i64 %idxprom27
  store i8 %31, i8* %arrayidx28, align 1
  br label %if.end29

if.end29:                                         ; preds = %if.else, %if.then21
  br label %while.cond, !llvm.loop !8

while.end:                                        ; preds = %while.cond
  %34 = load i8*, i8** %result, align 8
  %35 = load i32, i32* %i, align 4
  %idxprom30 = sext i32 %35 to i64
  %arrayidx31 = getelementptr inbounds i8, i8* %34, i64 %idxprom30
  store i8 0, i8* %arrayidx31, align 1
  %36 = load i8*, i8** %result, align 8
  ret i8* %36
}

; Function Attrs: nounwind readonly willreturn
declare i64 @strlen(i8* noundef) #1

; Function Attrs: nounwind readonly willreturn
declare i8* @strstr(i8* noundef, i8* noundef) #1

; Function Attrs: nounwind
declare noalias i8* @malloc(i64 noundef) #2

; Function Attrs: nounwind
declare i8* @strcpy(i8* noundef, i8* noundef) #2

; Function Attrs: noinline nounwind uwtable
define dso_local i32 @main() #0 {
entry:
  %retval = alloca i32, align 4
  %str = alloca [38 x i8], align 16
  %c = alloca [9 x i8], align 1
  %d = alloca [6 x i8], align 1
  %result = alloca i8*, align 8
  store i32 0, i32* %retval, align 4
  %0 = bitcast [38 x i8]* %str to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 16 %0, i8* align 16 getelementptr inbounds ([38 x i8], [38 x i8]* @__const.main.str, i32 0, i32 0), i64 38, i1 false)
  %1 = bitcast [9 x i8]* %c to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %1, i8* align 1 getelementptr inbounds ([9 x i8], [9 x i8]* @__const.main.c, i32 0, i32 0), i64 9, i1 false)
  %2 = bitcast [6 x i8]* %d to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %2, i8* align 1 getelementptr inbounds ([6 x i8], [6 x i8]* @__const.main.d, i32 0, i32 0), i64 6, i1 false)
  store i8* null, i8** %result, align 8
  %arraydecay = getelementptr inbounds [38 x i8], [38 x i8]* %str, i64 0, i64 0
  %call = call i32 (i8*, ...) @printf(i8* noundef getelementptr inbounds ([16 x i8], [16 x i8]* @.str, i64 0, i64 0), i8* noundef %arraydecay)
  %arraydecay1 = getelementptr inbounds [38 x i8], [38 x i8]* %str, i64 0, i64 0
  %arraydecay2 = getelementptr inbounds [9 x i8], [9 x i8]* %c, i64 0, i64 0
  %arraydecay3 = getelementptr inbounds [6 x i8], [6 x i8]* %d, i64 0, i64 0
  %call4 = call i8* @replaceWord(i8* noundef %arraydecay1, i8* noundef %arraydecay2, i8* noundef %arraydecay3)
  store i8* %call4, i8** %result, align 8
  %3 = load i8*, i8** %result, align 8
  %call5 = call i32 (i8*, ...) @printf(i8* noundef getelementptr inbounds ([16 x i8], [16 x i8]* @.str.1, i64 0, i64 0), i8* noundef %3)
  %4 = load i8*, i8** %result, align 8
  call void @free(i8* noundef %4) #6
  ret i32 0
}

; Function Attrs: argmemonly nofree nounwind willreturn
declare void @llvm.memcpy.p0i8.p0i8.i64(i8* noalias nocapture writeonly, i8* noalias nocapture readonly, i64, i1 immarg) #3

declare i32 @printf(i8* noundef, ...) #4

; Function Attrs: nounwind
declare void @free(i8* noundef) #2

attributes #0 = { noinline nounwind uwtable "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #1 = { nounwind readonly willreturn "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #2 = { nounwind "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #3 = { argmemonly nofree nounwind willreturn }
attributes #4 = { "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #5 = { nounwind readonly willreturn }
attributes #6 = { nounwind }

!llvm.module.flags = !{!0, !1, !2, !3, !4}
!llvm.ident = !{!5}

!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{i32 7, !"PIC Level", i32 2}
!2 = !{i32 7, !"PIE Level", i32 2}
!3 = !{i32 7, !"uwtable", i32 1}
!4 = !{i32 7, !"frame-pointer", i32 2}
!5 = !{!"Ubuntu clang version 14.0.0-1ubuntu1"}
!6 = distinct !{!6, !7}
!7 = !{!"llvm.loop.mustprogress"}
!8 = distinct !{!8, !7}
