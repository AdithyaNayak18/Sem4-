<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Student Course Registration</title>
    <style>
        .container {
            width: 50%;
            margin: auto;
        }
        .form-group {
            margin-bottom: 15px;
        }
        label {
            display: block;
        }
        input[type="text"], input[type="email"], input[type="tel"], select {
            width: 100%;
            padding: 8px;
            margin-top: 5px;
            box-sizing: border-box;
        }
        .result {
            margin-top: 20px;
            padding: 10px;
            border: 1px solid #ddd;
            background-color: #f9f9f9;
        }
    </style>
</head>
<body>
    <div class="container">
        <h2>Student Course Registration</h2>
        <form id="registrationForm">
            <div class="form-group">
                <label for="name">Student Name:</label>
                <input type="text" id="name" required>
            </div>
            <div class="form-group">
                <label for="usn">USN:</label>
                <input type="text" id="usn" required>
            </div>
            <div class="form-group">
                <label for="phone">Phone Number:</label>
                <input type="tel" id="phone" required>
            </div>
            <div class="form-group">
                <label for="email">Email ID:</label>
                <input type="email" id="email" required>
            </div>
            <div class="form-group">
                <label>Gender:</label>
                <input type="radio" name="gender" value="Male" required> Male
                <input type="radio" name="gender" value="Female" required> Female
                <input type="radio" name="gender" value="Other" required> Other
            </div>
            <div class="form-group">
                <label for="course">Course:</label>
                <select id="course" required>
                    <option value="">Select a course</option>
                    <option value="Computer Science">Computer Science</option>
                    <option value="Electronics">Electronics</option>
                    <option value="Mechanical">Mechanical</option>
                    <option value="Civil">Civil</option>
                    <option value="Electrical">Electrical</option>
                </select>
            </div>
            <button type="button" onclick="submitForm()">Submit</button>
            <button type="reset">Reset</button>
        </form>
        <div id="result" class="result" style="display:none;">
            <h3>Form Details</h3>
            <p><strong>Name:</strong> <span id="displayName"></span></p>
            <p><strong>USN:</strong> <span id="displayUSN"></span></p>
            <p><strong>Phone Number:</strong> <span id="displayPhone"></span></p>
            <p><strong>Email ID:</strong> <span id="displayEmail"></span></p>
            <p><strong>Gender:</strong> <span id="displayGender"></span></p>
            <p><strong>Course:</strong> <span id="displayCourse"></span></p>
        </div>
    </div>

    <script>
        function submitForm() {
            var name = document.getElementById('name').value;
            var usn = document.getElementById('usn').value;
            var phone = document.getElementById('phone').value;
            var email = document.getElementById('email').value;
            var gender = document.querySelector('input[name="gender"]:checked').value;
            var course = document.getElementById('course').value;

            document.getElementById('displayName').textContent = name;
            document.getElementById('displayUSN').textContent = usn;
            document.getElementById('displayPhone').textContent = phone;
            document.getElementById('displayEmail').textContent = email;
            document.getElementById('displayGender').textContent = gender;
            document.getElementById('displayCourse').textContent = course;

            document.getElementById('result').style.display = 'block';
        }
    </script>
</body>
</html>
