class KwicContainer extends React.Component {
    constructor() {
        super();
        this.state = {
            something: true
        };
    }
    render() {
        return (
            <div>
                <div className="row">
                    <div className="col-sm-12">
                        <InputField />
                    </div>
                </div>
                <div className="row">
                    <div className="col-sm-12">
                        <OutputField />
                    </div>
                </div>
            </div>
        )
    }
}

const OutputField = () => {
    return(
        <div>

        </div>
    )
}



(function() {
    ReactDOM.render(
        <KwicContainer />,
        document.getElementById('kwic-container')
    );
})();