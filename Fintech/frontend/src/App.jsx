import './App.css';
import { BrowserRouter as Router, Routes, Route } from 'react-router-dom';
import { RecoilRoot } from 'recoil';
import RazorpayDemo from './components/razorpayDemo';

function App() {
  return (
    <RecoilRoot>
      <Router>
        <Routes>
          <Route path="/" element={<RazorpayDemo />} />
        </Routes>
      </Router>
    </RecoilRoot>
  );
}

export default App;
