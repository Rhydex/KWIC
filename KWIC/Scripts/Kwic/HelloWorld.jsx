class HelloWorld extends React.Component {
    render() {
        return (
            <div>
                Hello World!
            </div>
        )
    };
}

$(document).ready(function() {
    ReactDOM.render(
        <HelloWorld />,
        document.getElementById("hello-container")
    );
});