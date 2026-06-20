# Group Member
#1. Cheryl Cheong Kah Voon(A23CS0060)
#2. Gui Kah Sin (A23CS0080)
#3. Lau Yee Wen (A23CS0099)
#4. Tan Sze Qing (A23CS5048)
#Link database:https://www.kaggle.com/datasets/iamsouravbanerjee/heart-attack-prediction-dataset


#1 sample hypothesis test on mean, variance unknown
ages <- heart_attack_prediction_dataset$Age
n=1000
s=sd(ages)
xbar=mean(ages)
mu=50
sd(ages)
mean(ages)
t=(xbar-mu)/(s/sqrt(n))
t
alpha=0.05
t.alpha=qt(1-alpha,df=n-1)
t.alpha
pval = pt(t, df=n-1, 
          lower.tail=FALSE)
pval

#2 Correlation Test
ages <- project2_dataset$Age
n=1000
cholesterol <- project2_dataset$Cholesterol

plot(ages, cholesterol, 
     main = "Scatter Plot of Age vs Cholesterol",
     xlab = "Age", 
     ylab = "Cholesterol",
     pch = 1,    # Shape of the points
     col = "black")  # Color of the points

ages <- as.numeric(as.character(project2_dataset$Age))
cholesterol <- as.numeric(as.character(project2_dataset$Cholesterol))

correlation <- cor(ages, cholesterol, method = "pearson")

print(paste("Pearson's correlation coefficient: ", correlation))

n <- 1000 
r <- correlation
t_statistic <- r * sqrt((n - 2) / (1 - r^2))
print(paste("Test Statistic: ", t_statistic))

alpha <- 0.05
df <- n - 2  
critical_value <- qt(1 - alpha / 2, df)
print(paste("Critical Value at 95% confidence level: ", critical_value))
decision <- ifelse(abs(t_statistic) > critical_value, "Reject the null hypothesis", "Fail to reject the null hypothesis")
print(paste("Decision: ", decision))

correlation_test <- cor.test(ages, cholesterol, method = "pearson")
print(correlation_test)


#3 Regression test
data <- read.csv("C://YEAR 1 SEM 2//PROBABILITY AND STATISTICAL ANALYSIS//project 2 (new dataset).csv")
head(data)
Heart.Rate <- data$`Heart Rate`
Heart.Rate <- data$Heart.Rate
BMI <- data$BMI
data_subset <- data.frame(Heart.Rate, BMI)
model <- lm(Heart.Rate ~ BMI, data = data_subset)
summary(model)
coefficients <- coef(model)
b0 <- coefficients[1]  # Intercept
b1 <- coefficients[2]  # Slope
cat("b0 (Intercept):", b0, "\n")
cat("b1 (Slope):", b1, "\n")
predicted_values <- predict(model)
mean_heart_rate <- mean(Heart.Rate)
SST <- sum((Heart.Rate - mean_heart_rate)^2)
SSE <- sum((Heart.Rate - predicted_values)^2)
SSR <- sum((predicted_values - mean_heart_rate)^2)
cat("SST (Total Sum of Squares):", SST, "\n")
cat("SSR (Sum of Squares due to Regression):", SSR, "\n")
cat("SSE (Sum of Squares due to Error):", SSE, "\n")
R_squared <- SSR / SST
cat("R-squared:", R_squared, "\n")
n <- length(Heart.Rate)
se <- sqrt(SSE / (n - 2))
mean_BMI <- mean(BMI)
sum_squares_BMI <- sum((BMI - mean_BMI)^2)
sb1 <- se / sqrt(sum_squares_BMI)
cat("se (Standard Error of Residuals):", se, "\n")
cat("sb1 (Standard Error of Slope):", sb1, "\n")
df <- n - 2
alpha <- 0.05
critical_value <- qt(1 - alpha/2, df)
cat("Critical value for two-tailed test at alpha = 0.05 and df =", df, ":", critical_value, "\n")
beta_1 <- 0  # Null hypothesis value
t_statistic <- (b1 - beta_1) / sb1
cat("t-statistic:", t_statistic, "\n")
plot(BMI, Heart.Rate,
     +      xlab = "BMI",
     +      ylab = "Heart Rate",
     +      xlim = c(15, 50),    # Set x-axis limit
     +      ylim = c(40, 140),   # Set y-axis limit
     +      pch = 1,             # Use circles for points
     +      main = "Scatter Plot of Heart Rate vs BMI")
abline(model, col="blue")
model


#4 Chi-Square Test of Independence
sex_obesity_table<- table(heart_attack_prediction_dataset$Sex, heart_attack_prediction_dataset$Obesity)
sex_obesity_table

alpha4<-0.05
df4 <- (nrow(sex_obesity_table) - 1) * (ncol(sex_obesity_table) - 1)
critical4=qchisq(alpha4,df=df4,lower.tail = FALSE)
critical4

chi_square_test<-chisq.test(sex_obesity_table)
print(chi_square_test)

print(paste("Alpha value:", alpha))
print(paste("Degrees of freedom:", df))
print(paste("Critical value:", critical_value))