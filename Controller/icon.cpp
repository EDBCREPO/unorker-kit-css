#pragma once

namespace uk { 

    express_tcp_t icon() {
        auto app = express::http::add();

        app.ALL([=]( express_http_t cli ){ cli.send();

            cli.write( _STRING_(

                .uk-icon::before, 
                .uk-icon-end::after,
                .uk-icon-begin::before { 
                    vertical-align: -webkit-baseline-middle;
                    font-family: 'Material Symbols Rounded';
                    vertical-align: text-bottom;
                    align-content: center;
                    font-weight: normal;
                    font-style: normal;
                    font-size: 24px;
                    line-height: 1;
                    content: attr(icon);
                    direction: ltr;
                    word-wrap: normal;
                    white-space: nowrap;
                    text-transform: none;
                    display: inline-block;
                    letter-spacing: normal;
                    -webkit-font-smoothing: antialiased;
                    -webkit-font-feature-settings: 'liga';
                }

            ));

        });

        return app;
    }

}