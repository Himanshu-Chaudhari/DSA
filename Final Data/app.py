from flask import Flask, render_template, request
import joblib
# Load your model here
import pandas as pd
loaded_model = joblib.load('/Users/himanshuchaudhari/Desktop/code/Final Data/Diseasemodel.pkl')
app = Flask(__name__)

@app.route('/')
def home():
    return render_template('form.html')

@app.route('/predict', methods=['POST'])
def predict():
    # Retrieve user input data from the form
    age = int(request.form['age'])
    gender = int(request.form['gender'])
    cholesterol = int(request.form['cholesterol'])
    heartRate = int(request.form['heartRate'])
    weight = float(request.form['weight'])
    height = int(request.form['height'])
    systolicBP = int(request.form['systolicBP'])
    diastolicBP = int(request.form['diastolicBP'])

    if(age<21):
        if(height > 80 + (age-1)*10 or height < 50):
            return ('Abnormal condition or improper inputs')
        if(weight >10 * (age-1)*5 or  weight > 120 ):
            return ('Abnormal condition or improper inputs')
        
    elif(((age>22 and height > 220 ) or height < 50 ) or (weight> 22 and weight >120) or weight< 20):
        return ('Abnormal condition or improper inputs')
    
    if(cholesterol > 400 or cholesterol < 100):
        return ('Abnormal condition or improper inputs')

    if(heartRate > 120 or heartRate <40):
        return ('Abnormal condition or improper inputs')
    
    if(heartRate > 120 or heartRate <40):
        return ('Abnormal condition or improper inputs')
    
    if(systolicBP < 85 or systolicBP >200):
        return ('Abnormal condition or improper inputs')
    
    if(diastolicBP < 50 or diastolicBP >120):
        return ('Abnormal condition or improper inputs')
    
    # Create a DataFrame with user input data
    user_input_data = {
        'Age': [age],
        'Gender': [gender],
        'Cholesterol': [cholesterol],
        'Heart Rate': [heartRate],
        'Weight': [weight],
        'Height': [height],
        'Systolic_BP': [systolicBP],
        'Diastolic_BP': [diastolicBP]
    }

    user_input_df = pd.DataFrame(user_input_data, columns=[
    'Age', 'Gender','Cholesterol', 'Heart Rate','Weight', 'Height', 'Systolic_BP', 'Diastolic_BP'])

    # Make predictions using the loaded model
    # Make predictions using the loaded model
    predicted_disease = loaded_model.predict(user_input_df)

    # Print the predicted class label
    print(f'Predicted Disease Label: {predicted_disease[0]}')


    # Map predicted labels to actual disease names
    disease_names = {0: 'None', 1: 'Diabetes', 2: 'Asthma', 3: 'Heart Disease'}


    # Check if the predicted label is a valid key
    if predicted_disease[0] in disease_names:
        predicted_disease_name = disease_names[predicted_disease[0]]
    # Display the predicted disease to the user
        return f'Predicted Disease: {predicted_disease_name}'
    else:
        return f'Predicted Disease: {predicted_disease[0]}'


if __name__ == '__main__':
    app.run(debug=True)
